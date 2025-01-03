class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        // vector<int> prefix(n+1 , 0);
        long long soa=accumulate(nums.begin(),nums.end(),0LL);
        long long leftsum=0 , rightsum=0;
        int count=0;
        
        for(int i=0;i<n-1;i++){
            leftsum+=nums[i];
            rightsum = soa-leftsum;

            if(leftsum >= rightsum) count++;
        }
        return count;
    }
};