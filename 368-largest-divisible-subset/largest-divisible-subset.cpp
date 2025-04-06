class Solution {
private:
    vector<int> solve(int& n , vector<int>& arr){
        vector<int> dp(n,1) , hash(n,0);
        sort(arr.begin(),arr.end());
        int maxi=1;
        int lastIndex=0;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev=0;prev<ind;prev++){
                if(arr[ind]%arr[prev]==0 && 1+dp[prev]>dp[ind]){
                    dp[ind]=1+dp[prev];
                    hash[ind]=prev;
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                lastIndex=ind;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        
        reverse(temp.begin(),temp.end());
        
        return temp;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        return solve(n , nums);
    }
};