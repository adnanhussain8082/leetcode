class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size() , n=isWater[0].size();
        // vector<vector<int>> visited(m,vector<int>(n,-1));
        vector<vector<int>> heights(m,vector<int>(n,-1));
        queue<pair<int,int>> q;

        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int height=0;
        while(!q.empty()){
            height++;

            int size = q.size();

            for(int i=0;i<size;i++){
                auto[x,y] = q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && heights[nx][ny]==-1){
                        heights[nx][ny]=height;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return heights;
    }
};