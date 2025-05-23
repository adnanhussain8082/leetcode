class Solution {
    #define ll long long
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans=0 , count=0 , discardedNode=INT_MAX;

        for(ll num : nums){
            ans += max(num , num^k);
            count += (num^k)>num;
            discardedNode = min(discardedNode , abs(num - (num^k)));
        }

        return (count & 1)==0 ? ans : (ans-discardedNode);
    }
};