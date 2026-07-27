class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return (nums[size(nums)-1]-1)*(nums[size(nums)-2]-1);
    }
};
