class Solution {
public:
    int maximumSum(vector<int>& nums) {
       int res=-1 , hash[82]={};   //why 82 check notes

       for(int x : nums){
        int d=0;
        for(int n=x;n>0;n/=10){
            d += n%10;    //gives the sum of digits of a particular nums[i]
        }

        if(hash[d]){
            res = max(res , hash[d]+x);
        }
        hash[d] = max(hash[d] , x);

       }

       return res;
    }
};