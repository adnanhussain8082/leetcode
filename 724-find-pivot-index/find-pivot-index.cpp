class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        int cs=0;   //cumulative sum
        for(int i=0;i<n;i++){
            int ls=cs;      //left sum
            int rs = sum - cs - nums[i];
            cs+=nums[i]; 

            if(ls==rs){
            return i;
        }
        }
            return -1;
        
    }
};