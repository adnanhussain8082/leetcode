class Solution {
public:
    int helper(vector<int>& nums, int index , int CurrentXOR){
        //base case
        if(index==nums.size()) return CurrentXOR;

        //CurrentXOR with current element
        int withElement=helper(nums , index+1 , CurrentXOR^nums[index]);

        //CurrentXOR without current element
        int withoutElement=helper(nums , index+1 , CurrentXOR);

        //final return the sum
        return withElement+withoutElement;
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(nums , 0 , 0);
        
    }
};