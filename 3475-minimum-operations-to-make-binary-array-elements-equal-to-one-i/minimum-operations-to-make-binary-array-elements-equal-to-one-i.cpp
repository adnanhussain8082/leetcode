class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int presum=0;
        int minFlips=0;

        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];

                minFlips++;
            }
            presum+=nums[i];
        }

        presum = presum + nums[n-2] + nums[n-1];

        int resultantsum = n;

        if(presum!=n) return -1;

        return minFlips;
    }
};