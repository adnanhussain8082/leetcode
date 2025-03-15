class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
       int left=1 , right=1e9 , n=nums.size();

       while(left<right){
        int mid = left + (right-left)/2 , take=0;

        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                take++;
                i++;
            }
        }

        if(take >= k){
            right=mid; //this can be my answer, but look for smaller in the left
        }
        else{  //take < k  , with the current chosen mid(current capability) he's not even able to rob k houses, so move right 
            left = mid+1;
        }
       }

       return left;  //left==right
    }
};