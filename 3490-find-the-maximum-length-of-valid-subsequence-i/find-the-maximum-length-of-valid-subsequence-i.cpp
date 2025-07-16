class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd_count = (nums[0]&1)==1;
        int even_count = (nums[0]&1)!=1;
        int alternating_count=1;
        bool expecting_even = (nums[0]&1) ? true : false;

        for(int i=1;i<nums.size();i++){
            if((expecting_even==true and (nums[i]&1)!=1) or (expecting_even==false and (nums[i]&1)==1)){
                alternating_count++;
                expecting_even = !expecting_even;
            }

            if(nums[i]&1) odd_count++;
            else even_count++;
        }

        return max({odd_count , even_count , alternating_count});
    }
};