class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size() , i = 0 , res = 0;
        int k = unordered_set<int>(nums.begin() , nums.end()).size();
        unordered_map<int,int> count;

        for(int j=0;j<nums.size();j++){
            k -= count[nums[j]]++ == 0;

            while(k==0){
                k += --count[nums[i++]] == 0;
            } 

            res += i;
        }

        return res;
    }
};