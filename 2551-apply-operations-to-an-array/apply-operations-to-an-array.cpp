class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int zeroCnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0) zeroCnt++;
            else if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        if(nums[n-1]==0) zeroCnt++;
        cout<<zeroCnt;

        int i=0;
        for(auto& ele : nums){
            if(ele!=0) nums[i++]=ele;
        }

        while(i < n){
            nums[i++]=0;
        }

        return nums;
    }
};