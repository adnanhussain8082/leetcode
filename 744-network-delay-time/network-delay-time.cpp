class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> time(n+1 , 1e9);
        time[k]=0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;
        minHeap.push({0,k});

        while(!minHeap.empty()){
            int t = minHeap.top().first;
            int node =minHeap.top().second;
            minHeap.pop();

            for(auto [ne , wt] : adj[node]){
                if(t+wt < time[ne]){
                    time[ne] = t+wt;
                    minHeap.push({time[ne] , ne});
                }
            }
        }

        int maxTime = *max_element(time.begin()+1 , time.end());

        return maxTime==1e9 ? -1 : maxTime;
    }
};