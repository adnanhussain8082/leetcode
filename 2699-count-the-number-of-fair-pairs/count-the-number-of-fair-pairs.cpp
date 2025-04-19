class Solution {
private:
    long long countLess(vector<int>& nums, int val){
        long long cnt=0;
        int n=nums.size();

        for(int i=0,j=n-1;i<j;i++){
            while(i<j && nums[i]+nums[j]>val){
                j--;
            }
            cnt += j-i;
        }
        return cnt;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return countLess(nums , upper) - countLess(nums , lower-1);
    }
};