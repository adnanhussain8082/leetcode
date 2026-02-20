class Solution {
public:
    void combinationSum2_Helper(vector<int>& candidates, int target , vector<int>& v , vector<vector<int>>& ans , int index){
        //base case-1
        if(target==0){
            ans.push_back(v);
            return;
        }

        //base case-2
        if(target<0){
            return;
        }

        //sol for one case
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            //RE
            combinationSum2_Helper(candidates , target-candidates[i] , v , ans , i+1);
            //backtracking
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;

        combinationSum2_Helper(candidates , target , v , ans , 0);

        return ans;
        
    }
};