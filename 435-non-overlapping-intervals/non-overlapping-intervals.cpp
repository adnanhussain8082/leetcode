class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1]<b[1];
        });
        int ct=0;

        vector<int> curr = nums[0];

        for(int i=1;i<nums.size();i++){
            if(curr[1]>nums[i][0]){
                ct++;
            }
            else curr = nums[i];
        }
        return ct;
    }
};