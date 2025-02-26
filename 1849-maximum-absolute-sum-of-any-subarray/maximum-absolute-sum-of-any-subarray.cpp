class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s=0 , mi=0 , ma=0 ; // prefixSum , minimum , maximum
        for(auto& x : nums){
            s += x;
            mi = min(mi , s);
            ma = max(ma , s);
        }
        return ma-mi;
    }
};