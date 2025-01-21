class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = accumulate(grid[0].begin(),grid[0].end(),0ll) , res=LLONG_MAX , bottom=0;
        int n=grid[0].size();

        for(int i=0;i<n;i++){
            top -= grid[0][i];
            res = min(res , max(top,bottom));
            bottom += grid[1][i];
        }
        return res;
    }
};