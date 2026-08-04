class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        vector<int> tym(n+1,1e9); //tym=time
        minHeap.push({0,k});  //k=src
        tym[k]=0;

        while(!minHeap.empty()){
            auto it=minHeap.top();
            minHeap.pop();

            int timee=it.first;
            int node=it.second;

            for(auto it : adj[node]){
                int adjNode=it.first;
                int edgeWt=it.second;

                if(timee+edgeWt < tym[adjNode]){
                    tym[adjNode]=timee+edgeWt;
                    minHeap.push({tym[adjNode],adjNode});
                }
            }
        }

        auto maxTime = *(max_element(tym.begin()+1,tym.end())); 
        //+1 bcoz there is 0 index also present and it 
        //will always have value=1e9 bcoz the nodes are labelled from 1 to n

        return (maxTime==1e9) ? -1 : maxTime;
    }
};