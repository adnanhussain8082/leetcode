class Solution {
private:
    void backtrack(int start , int& n , int& k , vector<int>& temp , vector<vector<int>>& ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int num=start;num<=n;num++){
            temp.push_back(num);
            backtrack(num+1 , n , k , temp , ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(1 , n , k , temp , ans);

        return ans;
    }
};