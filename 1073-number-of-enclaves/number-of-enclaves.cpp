class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m , vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int j=0;j<n;j++){
            
            if(grid[0][j]==1 and vis[0][j]==0){
                q.push({0 , j});
                vis[0][j]=1;
            }

            if(grid[m-1][j]==1 and vis[m-1][j]==0){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }

        for(int i=0;i<m;i++){

            if(grid[i][0]==1 and vis[i][0]==0){
                q.push({i,0});
                vis[i][0]=1;
            }

            if(grid[i][n-1]==1 and vis[i][n-1]==0){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]==1 and vis[nrow][ncol]==0){
                    q.push({nrow , ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }

        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=vis[i][j]) count++;
            }
        }

        return count;
    }
};