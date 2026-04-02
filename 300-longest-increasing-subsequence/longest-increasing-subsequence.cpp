class Solution {
private:
    //method2:Memoization
    int solve2(int ind , int prev_ind , vector<int>& nums , vector<vector<int>>& dp){
        //base case
        if(ind==nums.size()) return 0;

        //Memoization check
        //and prev_ind+1 bcoz shifting cuz -1 can't be index of dp
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        //REC
        int notTake=0+solve2(ind+1 , prev_ind , nums , dp);
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            take=1+solve2(ind+1 , ind , nums , dp);
        }
        return dp[ind][prev_ind+1]=max(take , notTake);
    }

    //method3:Tabulation
    int solve3(int& n , vector<int>& nums){
        vector<vector<int>> dp(n+1,vector<int>(n+1 , 0));

        //nested loops
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                //paste the recurence
                int notTake=0+dp[ind+1][prev_ind+1];
                int take=0;
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                    take=1+dp[ind+1][ind+1];
                }
                dp[ind][prev_ind+1]=max(take , notTake);
            }
        }

        return dp[0][-1+1];
    }

    //method4:space optimization
    int solve4(int& n , vector<int>& nums){
        vector<int> curr(n+1 , 0) , next(n+1 , 0);

        //nested loops
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){   //because prev_ind 
                //paste the recurence
                int notTake=0+next[prev_ind+1];
                int take=0;
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                    take=1+next[ind+1];
                }
                curr[prev_ind+1]=max(take , notTake);
            }
            next=curr;
        }

        return next[-1+1];
    }

    //method5:Tabulation Algorithm
    int solve5(int& n , vector<int>& nums){
        vector<int> dp(n , 1);

        int maxi=1;
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(nums[prev]<nums[ind]){
                    dp[ind]=max(dp[ind] , 1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[ind]);
        }

        return maxi;
    }

    //method6: using binary search to run it in O(n log(n)) time complexity
    //but remember this will not give us the LIS
    //instead it will give us length of LIS
    //because we will overwrite some elements along the way
    //which would not let it be the subsequence 

    int solve6(int& n, vector<int>& nums){
    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;

    for(int i = 1; i < n; i++){
        if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return len;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        //method2:
        // vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        // return solve2(0 , -1 , nums , dp);

        //method3:
        // return solve3(n , nums);

        //method4:
        // return solve4(n , nums);

        //method5:
        // return solve5(n , nums);

        //method6: using binary search instead of inner loop
        return solve6(n , nums);

    }
};