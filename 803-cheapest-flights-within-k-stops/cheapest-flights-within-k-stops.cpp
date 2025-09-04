class Solution {
public:        //TC=O(E) E--->no of edges
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> Adj[n];
        for(auto it : flights){
            Adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;  //{stops,{node,cost}}
        vector<int> cost(n,1e9);
        q.push({0,{src,0}});
        cost[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int costt=it.second.second;

            //if stops>k
            if(stops>k) continue;

            for(auto it : Adj[node]){
                int adjNode=it.first;
                int edgeWt=it.second;

                if(costt+edgeWt < cost[adjNode]){
                    cost[adjNode]=costt+edgeWt;
                    q.push({stops+1,{adjNode,cost[adjNode]}});
                }
            }
        }

        if(cost[dst]!=1e9){
            return cost[dst];
        }

        return -1;
    }
};