class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        vector<int> diffArr(n,0);

        for(auto& it : queries){
            diffArr[it[0]] += 1;

            if(it[1]+1 < n) diffArr[it[1]+1] -= 1;
        }

        for(int i=1;i<n;i++){
            diffArr[i] += diffArr[i-1];
        }

        for(int i=0;i<n;i++){
            if(diffArr[i] < nums[i]) return false;
        }

        return true;
    }
};