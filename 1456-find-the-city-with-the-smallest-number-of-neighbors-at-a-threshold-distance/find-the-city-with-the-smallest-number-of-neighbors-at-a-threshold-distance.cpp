class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m=edges[0].size();

        vector<pair<int,int>> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<vector<int>> distances;
        

        //generate min distance of every vertex from every other vertex using dijkstra algo
        for(int src=0;src<n;src++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
            vector<int> dis(n,INT_MAX);

            minHeap.push({0,src});
            dis[src]=0;

            while(!minHeap.empty()){
                int dist=minHeap.top().first;
                int node=minHeap.top().second;
                minHeap.pop();

                for(auto it : adj[node]){
                    int adjNode=it.first;
                    int edgeWt=it.second;

                    if(dist+edgeWt < dis[adjNode]){
                        dis[adjNode]=dist+edgeWt;
                        minHeap.push({dist+edgeWt , adjNode});
                    }
                }
            }

            distances.push_back(dis);
        }

        int cityNo=-1;
        int cityCount=n;

        for(int city=0;city<n;city++){
            int count=0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(distances[city][adjCity]<=distanceThreshold){
                    count++;
                }
            }
            if(count <= cityCount){
                cityCount=count;
                cityNo=city;
            }
        }

        return cityNo;

    }
};