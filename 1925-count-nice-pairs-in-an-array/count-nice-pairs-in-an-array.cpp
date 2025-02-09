class Solution {
private:
    int rev(int num){
        int reve=0;
        while(num>0){
            reve = reve*10 + num%10;
            num /= 10;
        }
        return reve;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();

        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        //   or by rearraging the terms
        // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])

        unordered_map<int,int> mpp;

        long long cnt=0;
        const int Mod = 1e9 + 7;

        for(int i=0;i<n;i++){
            cnt += mpp[nums[i]-rev(nums[i])]++;
        }

        return cnt % Mod;
    }
};