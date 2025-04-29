class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int a = *max_element(nums.begin(),nums.end());
        int cur=0 , i=0;

        long long count=0;

        for(int j=0;j<nums.size();j++){
            cur += nums[j]==a;

            while(cur >= k){
                cur -= nums[i++]==a;
            }

            count += i;
        }
        return count;
    }
};