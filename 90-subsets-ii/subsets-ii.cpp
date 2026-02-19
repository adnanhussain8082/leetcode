class Solution {
private:
    void f(int idx , vector<int>& nums , vector<int>& temp , vector<vector<int>>& ans){
        ans.push_back(temp);

        for(int i=idx;i<nums.size();i++){
            if(i>idx and nums[i]==nums[i-1]) continue; //check for duplicates

            temp.push_back(nums[i]);
            f(i+1 , nums , temp , ans);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<int> temp;
        vector<vector<int>> ans;

        f(0 , nums , temp , ans);

        return ans;
    }
};