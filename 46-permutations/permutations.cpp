class Solution {
private:
    void f(int i , vector<int>& nums , vector<vector<int>>& ans){
        //base case
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++){

            //one case
            swap(nums[i],nums[j]);

            f(i+1 , nums , ans);

            //backtracking
            swap(nums[i],nums[j]);

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        f(0 , nums , ans);

        return ans;
    }
};