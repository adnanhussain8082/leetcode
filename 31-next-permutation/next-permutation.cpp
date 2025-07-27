class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //  1st method using STL fn next_permutation
        // next_permutation(nums.begin() , nums.end());

        //2nd method(implement the above stl fn)
        int index , k , n=nums.size();

        for(index=n-2;index>=0;index--){
            if(nums[index]<nums[index+1]){
                break;
            }
        }

        if(index < 0){ //e.g {3,2,1} //edge case
            reverse(nums.begin(),nums.end());
        }
        else{
            for(k=n-1;k>index;k--){  //search for the just big element than nums[index] or dip element in the suffix part of the array
                if(nums[k]>nums[index]){
                    break;
                }
            }

            swap(nums[k],nums[index]);
            //now reverse the suffix part after index
            reverse(nums.begin()+index+1 , nums.end());
        }
    }
};