class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0;
        int maxa=0 , maxab=0;

        for(auto& a : nums){
            //3rd step : deal with nums[i],nums[j],nums[k]
            res = max(res , (long long) maxab*a);

            //2nd step : deal with nums[i],nums[j]
            maxab = max(maxab , maxa-a);

            //ist step : deal with nums[i]
            maxa = max(maxa , a);
        }
        return res;










        // long long ans=0;
        // int n=nums.size();

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             ans = max(ans , (long long)(nums[i]-nums[j])*nums[k]);
        //         }
        //     }
        // }
        // return ans;
    }
};