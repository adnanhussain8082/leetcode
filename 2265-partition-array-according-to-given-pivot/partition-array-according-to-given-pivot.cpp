class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();

        vector<int> ans;

        int cnt = count(nums.begin(),nums.end(),pivot);

        for(auto& it : nums){
            if(it < pivot) ans.push_back(it);
        }

        while(cnt){
            ans.push_back(pivot);
            cnt--;
        }

        for(auto& it : nums){
            if(it > pivot) ans.push_back(it);
        }

        return ans;
    }
};