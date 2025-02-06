class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mpp[nums[i]*nums[j]]++;
            }
        }

        int ans=0;

        for(auto& x : mpp){
            ans += 4*(x.second*(x.second-1));
        }

        return ans;
    }
};