class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto& it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> minHeap;
        minHeap.push({0,0});

        vector<long long> time(n , 1e18);
        time[0]=0;

        vector<long long> ways(n , 0);
        ways[0]=1;

        int mod = (int)(1e9+7);

        while(!minHeap.empty()){
            long long t = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            for(auto [ne , wt] : adj[node]){
                if(t+wt < time[ne]){
                    time[ne] = t+wt;
                    ways[ne] = ways[node];
                    minHeap.push({t+wt , ne});
                }

                else if(t+wt == time[ne]){
                    ways[ne] = (ways[ne] + ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};