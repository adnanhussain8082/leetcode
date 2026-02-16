class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIndex=0;
        for(int i=0;i<n;i++){
            //we just have to reach the end, no min cost condition is there

            if(i>maxIndex) return false; //if maxIndex lands on some index where nums[i]==0

            maxIndex=max(maxIndex , i+nums[i]);

            if(maxIndex>=n-1){
                return true;
            }
        }

        return true;
    }
};