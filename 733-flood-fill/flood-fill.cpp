class Solution {
private:
    void dfs(int& color , int& initialColor , int row , int col , vector<vector<int>>& image , vector<vector<int>>& ans , int drow[] , int dcol[]){
        ans[row][col] = color;

        int m=image.size();
        int n=image[0].size();

        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and image[nrow][ncol]==initialColor and ans[nrow][ncol]!=color){
                dfs(color , initialColor , nrow , ncol , image , ans , drow , dcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        dfs(color , initialColor , sr , sc , image , ans , drow , dcol);

        return ans;
    }
};