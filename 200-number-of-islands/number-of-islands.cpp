class Solution {
private:
    void bfs(int i , int j , vector<vector<int>>& vis , vector<vector<char>>& grid){
        vis[i][j]=1;

        int m=grid.size() , n=grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});

        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow>=0 and nrow < m and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]=='1'){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    bfs(i , j , vis , grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};