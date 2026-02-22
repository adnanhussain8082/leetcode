class Solution {
public:
    int search(vector<int>& nums, int target) {
        //pivot element wala soln is saved in note(love babbar)
        //striver sol:
        int s=0 , e=nums.size()-1 , mid;

        while(s<=e){
            mid=s+(e-s)/2;

            if(nums[mid]==target){
                return mid;
            }

            //left side sorted
            else if(nums[s]<=nums[mid]){

                //check for the target in this range
                if(nums[s]<=target && target<=nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }

            //right side sorted
            else{

                //check for the target in this range
                if(nums[mid]<=target && target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }

        return -1;
    }
};