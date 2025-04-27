class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt=0 , j=0;

        for(int i=0;i<nums.size()-2;i++){

            if(double(nums[i]+nums[i+2])==(double)nums[i+1]/2) cnt++;
        }

        return cnt;
    }
};