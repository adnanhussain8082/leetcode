class Solution {
private:
    void f(int idx , int target , vector<int>& candidates , vector<int>& temp , vector<vector<int>>& ans){
        //base cases
        if(target==0){
            ans.push_back(temp);
        }
        if(target<0) return;

        for(int i=idx;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            f(i , target-candidates[i] , candidates , temp , ans);
            //backtracking
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;

        f(0 , target , candidates , temp , ans);

        return ans;
    }
};