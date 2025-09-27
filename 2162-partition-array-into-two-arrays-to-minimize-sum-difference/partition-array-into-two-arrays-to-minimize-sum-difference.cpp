class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        //this will not be solved using dp
        //instead "MEET IN THE MIDDLE" is used(aryan mittal)
        //mathematical derivation of b is on notebook

        int N=nums.size();
        int n=N/2 , res=0;
        vector<vector<int>> left(n+1) , right(n+1);
        int sum = accumulate(nums.begin(),nums.end(),0);

        for(int mask=0;mask<(1<<n);mask++){
            int sz=0 , l=0 , r=0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    sz++;
                    l += nums[i];
                    r += nums[i+n];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        res = min( abs(sum-2*left[n][0]) , abs(sum-2*right[n][0]) );

        for(int sz=0;sz<=n;sz++){
            sort(right[sz].begin(),right[sz].end());
        }

        //iterate over left part
        for(int sz=1;sz<=n;sz++){
            for(int a : left[sz]){
                int b = (sum - 2*a)/2 , rsz = n-sz;
                auto& v = right[rsz];

                auto itr = lower_bound(v.begin(),v.end(),b); //binary search

                if(itr!=v.end()) res = min(res , abs(sum - 2*(a+(*itr))));

                if(itr!=v.begin()){
                    auto it = itr;
                    --it;
                    res = min(res , abs(sum - 2*(a+(*it))));
                }
            }
        }

        return res;
    }
};