class Solution {
public:
    //soln link in notes
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        unordered_map<int,int> mpp;

        //total pairs = valid pairs(good pairs) - invalid pairs(bad pairs)
        //total pairs = n*(n-1)/2  ---> typecast it by 1L 


        for(int i=0;i<nums.size();i++){
            cnt += mpp[i-nums[i]]++;
        }

        return 1L*n*(n-1)/2 - cnt;
    }
};