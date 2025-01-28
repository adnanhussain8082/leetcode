class Solution {
private:
    void dfs(int i , int j , int& m , int& n , int& curr , vector<vector<int>>& grid , vector<vector<int>>& vis){
        vis[i][j]=1;
        curr += grid[i][j];

        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        for(int k=0;k<4;k++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];

            if(x>=0 && x<m && y>=0 && y<n && vis[x][y]==-1){
                dfs(x , y , m , n , curr , grid , vis);
            }
        }
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size() , n=grid[0].size();

        vector<vector<int>> vis(m , vector<int>(n,-1));
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;  //mark the land cells as already visited
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==-1){    //not a land cell and is unvisited
                    int curr=0;
                    dfs(i , j , m , n , curr , grid , vis);
                    ans = max(ans , curr);
                }
            }
        }

        return ans;
    }
};