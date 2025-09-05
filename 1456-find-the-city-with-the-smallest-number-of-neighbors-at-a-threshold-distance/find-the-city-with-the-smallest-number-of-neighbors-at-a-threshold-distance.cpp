class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<vector<int>> distances;

        for(int src=0;src<n;src++){
            priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;
            minHeap.push({0,src});

            vector<int> dis(n,1e9);
            dis[src]=0;

            while(!minHeap.empty()){
                int node=minHeap.top().second;
                int dist=minHeap.top().first;
                minHeap.pop();

                for(auto [ne , wt] : adj[node]){
                    if(dist+wt < dis[ne]){
                        dis[ne] = dist+wt;
                        minHeap.push({dis[ne],ne});
                    }
                }
            }

            distances.push_back(dis);
        }

        int cityNum=-1;
        int cityCnt=n;  //initializing it with n because i need some max number bc question asks for min city

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(distances[i][j] <= distanceThreshold){
                    count++;
                }
            }

            if(count <= cityCnt){
                cityCnt = count;
                cityNum = i;
            }
        }

        return cityNum;
    }
};