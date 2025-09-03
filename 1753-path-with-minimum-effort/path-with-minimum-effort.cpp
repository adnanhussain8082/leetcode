class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size() , n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;

        vector<vector<int>> dist(m , vector<int>(n,1e9));

        minHeap.push({0,{0,0}});

        dist[0][0] = 0;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!minHeap.empty()){
            int diff = minHeap.top().first;
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            minHeap.pop();

            if(row==m-1 and col==n-1) return diff;

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n){
                    int newEffort = max(abs(heights[row][col]-heights[nrow][ncol]) , diff);

                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        minHeap.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }

        return 0; //unreachable
    }
};