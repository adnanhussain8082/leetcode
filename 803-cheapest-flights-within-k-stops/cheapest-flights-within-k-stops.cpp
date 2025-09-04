class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto& it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src , 0}});

        vector<int> cost(n,1e9);
        cost[src]=0;

        while(!q.empty()){
            int node = q.front().second.first;
            int costt = q.front().second.second;
            int stop = q.front().first;
            q.pop();

            if(stop>k) continue;

            for(auto [ne,wt] : adj[node]){
                if(costt+wt <= cost[ne]){
                    cost[ne] = costt+wt;
                    q.push({stop+1 , {ne , cost[ne]}});
                }
            }
        }

        if(cost[dst]!=1e9) return cost[dst];

        return -1; 
    }
};