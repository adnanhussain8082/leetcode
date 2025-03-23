class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> minHeap;
        vector<long long> time(n,1e18);
        vector<long long> ways(n,0);
        minHeap.push({0,0});
        time[0]=0;
        ways[0]=1;

        int mod=(int)(1e9+7);

        while(!minHeap.empty()){
            long long timee=minHeap.top().first;
            int node=minHeap.top().second;
            minHeap.pop();

            for(auto it : adj[node]){
                int adjNode=it.first;
                long long edgeWt=it.second;

                if(timee+edgeWt < time[adjNode]){
                    time[adjNode]=timee+edgeWt;
                    minHeap.push({time[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(timee+edgeWt == time[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};