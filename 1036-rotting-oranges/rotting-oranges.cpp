class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<pair<int,int> , int>> q;

        vector<vector<int>> vis(m , vector<int>(n,0));
        int countFresh=0 , count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    countFresh++;
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int tmax = 0;

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tmax = max(tmax , t);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]!=0 and vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                    count++;
                }
            }
        } 

        if(countFresh != count) return -1;

        return tmax;
    }
};