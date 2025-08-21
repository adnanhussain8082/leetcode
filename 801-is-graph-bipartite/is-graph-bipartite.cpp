class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> colors(V , -1);

        queue<int> q;

        for(int i=0;i<V;i++){
            if(colors[i]==-1){

                q.push(i);
                colors[i]=0;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int ne : graph[node]){
                        if(colors[ne]==-1){
                            colors[ne] = !colors[node];
                            q.push(ne);
                        }

                        else if(colors[ne]==colors[node]){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};