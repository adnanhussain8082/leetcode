class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];

        for(int i=1;i<n;i++){
            prefix[i] = nums[i] + prefix[i-1];
        }

        unordered_map<int,int> mpp;
        int ans=0;

        for(int i=0;i<n;i++){
            if(prefix[i]==k) ans++;

            if(mpp.find(prefix[i]-k)!=mpp.end()){
                ans+=mpp[prefix[i]-k];
            }

            mpp[prefix[i]]++;
        }

        return ans;
    }
};