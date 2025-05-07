class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size() , m=moveTime[0].size();

        vector<vector<int>> time(n , vector<int>(m , INT_MAX));
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> minHeap;

        minHeap.push({0 , 0 , 0});

        vector<vector<int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};
        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();
            int currTime = it[0];
            int i = it[1] , j = it[2];

            if(currTime >= time[i][j]) continue;

            time[i][j] = currTime;

            if(i==n-1 && j==m-1) return currTime;


            for(auto& it : dir){
                int nrow = i + it[0];
                int ncol = j + it[1];

                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m){
                    int nextTime = max(currTime , moveTime[nrow][ncol]) + 1;
                    if(nextTime < time[nrow][ncol]){
                        minHeap.push({nextTime , nrow , ncol});
                    }
                }
            }
        }
        return time[n-1][m-1];
    }
};