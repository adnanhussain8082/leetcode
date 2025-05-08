class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<vector<int>>> time(n, vector<vector<int>>(m, vector<int>(2, INT_MAX))); // time[i][j][parity]

        // minHeap stores: {currTime, i, j, stepParity}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0, 0}); // start at time 0, (0,0), next move is 1-sec (step 0 => even)

        vector<vector<int>> dir = {{0,1},{-1,0},{0,-1},{1,0}};

        while (!minHeap.empty()) {
            auto it = minHeap.top();
            minHeap.pop();

            int currTime = it[0];
            int i = it[1], j = it[2], parity = it[3];

            if (currTime >= time[i][j][parity]) continue;
            time[i][j][parity] = currTime;

            if (i == n - 1 && j == m - 1) return currTime;

            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int moveCost = (parity == 0 ? 1 : 2);
                    int arriveTime = max(currTime, moveTime[ni][nj]) + moveCost;
                    int nextParity = 1 - parity;
                    if (arriveTime < time[ni][nj][nextParity]) {
                        minHeap.push({arriveTime, ni, nj, nextParity});
                    }
                }
            }
        }
        return -1; // unreachable
    }
};
