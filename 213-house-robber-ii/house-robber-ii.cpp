class Solution {
private:
    int solve(vector<int>& arr){
        int n=arr.size();
        int prev2=0;
        int prev=arr[0];

        for(int i=1;i<n;i++){
            int pick=arr[i]+prev2;
            int notpick=0+prev;

            int curr_i=max(pick,notpick);

            prev2=prev;
            prev=curr_i;
        }

        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        //we will take two temporary vectors one starting from second element and another without last element
        vector<int> temp1 , temp2;

        //get the first vector
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        int ans1=solve(temp1);
        int ans2=solve(temp2);

        return max(ans1,ans2);

    }
};