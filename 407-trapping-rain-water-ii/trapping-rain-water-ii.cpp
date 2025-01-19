class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size() , n=heightMap[0].size();

        if(m<=2 || n<=2) return 0;  // No water can be trapped if the grid is too small.

        int totalRain=0;
        //minHeap
        //Priority queue to store cells in ascending order of height
        typedef pair<int,pair<int,int>> ppi;
        priority_queue<ppi,vector<ppi>,greater<ppi>> minHeap;
        
        vector<vector<bool>> visited(m , vector<bool>(n,0));

        // Directions for exploring neighbors
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

        //Add all boundary cells to the priority queue and mark them as visited
        for(int i=0;i<m;i++){
            minHeap.push({heightMap[i][0] , {i,0}});   //height of a particaular(boundary) cell and its coordinates
            minHeap.push({heightMap[i][n-1] , {i,n-1}});
            visited[i][0]=visited[i][n-1]=1;
        }

        for(int j=1;j<n-1;j++){
            minHeap.push({heightMap[0][j] , {0,j}});
            minHeap.push({heightMap[m-1][j] , {m-1,j}});
            visited[0][j]=visited[m-1][j]=1;
        }

        while(!minHeap.empty()){
            auto[height,cell]=minHeap.top();
            minHeap.pop();
            int x=cell.first , y=cell.second;

            for(auto[dx,dy] : dir){
                int nx=x+dx , ny=y+dy;

                // Check bounds and if the neighbor has already been visited
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny]){

                    //Water trapped at this cell is the difference between the current height and the neighbor height
                    totalRain += max(0 , height-heightMap[nx][ny]);

                    // Update the neighbor's height to the max of its own height and the current height
                    minHeap.push({max(height,heightMap[nx][ny]),{nx,ny}});

                    visited[nx][ny]=1;
                }
            }
        }
        return totalRain;
    }
};