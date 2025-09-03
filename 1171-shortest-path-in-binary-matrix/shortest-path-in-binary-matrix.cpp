class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();     //GRID=mxm

        //edge cases
        if(grid[0][0]==1 or grid[m-1][m-1]==1) return -1;
        if(m==1 and grid[0][0]==0) return 1;

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dis(m,vector<int>(m,1e9));

        q.push({1,{0,0}});
        dis[0][0]=1;

        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 and nrow<m and ncol>=0 and ncol<m and grid[nrow][ncol]==0 and (dist+1 < dis[nrow][ncol])){
                    dis[nrow][ncol] = dist+1;

                    if(nrow==m-1 and ncol==m-1) return dist+1;

                    q.push({dist+1 , {nrow,ncol}});
                }
            }
        }

        return -1;
    }
};