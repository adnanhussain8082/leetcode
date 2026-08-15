class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool nonZero = false;

        for(int num : nums){
            totalXor^=num;
            nonZero = nonZero or (num>0);
        }

        if(totalXor) return nums.size();

        if(nonZero) return nums.size()-1;

        return 0;
    }
};