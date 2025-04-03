class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //same concept as that of Maximum Value of an Ordered Triplet I

        long long res=0;
        long long maxa=0 , maxab=0;

        for(auto& a : nums){
            res = max(res , maxab*a);

            maxab = max(maxab , maxa-a);

            maxa = max(maxa , (long long) a);
        }
        return res;
    }
};