class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count=0 , sum=0;

        int i=0 , j=0;

        for(;j<nums.size();j++){
            sum += nums[j];

            while(sum * (j-i+1) >= k)
                sum -= nums[i++];
            
            count += j-i+1;
        }
        return count;
    }
};