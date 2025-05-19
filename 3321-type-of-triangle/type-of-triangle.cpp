class Solution {
public:
    string triangleType(vector<int>& nums) {
        //check valid triangle or not
        if(!((nums[0]+nums[1] > nums[2]) && (nums[1]+nums[2] > nums[0]) && (nums[0]+nums[2] > nums[1]))){
            return "none";
        }

        //check for equilateral
        if(nums[0]==nums[1] && nums[1]==nums[2]){
            return "equilateral";
        }

        //check for scalene
        else if(nums[0]!=nums[1] && nums[0]!=nums[2] && nums[1]!=nums[2]){
            return "scalene";
        }

        //if none of the above satisfied then it is isosceles
        return "isosceles";
    }
};