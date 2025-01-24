class Solution {
public:
    bool dfs_method(int node , vector<vector<int>>& graph , vector<int>& Vis , vector<int>& pathVis , vector<int>& check){
        Vis[node]=1;
        pathVis[node]=1;
        check[node]=0; //just to make sure it is zero for every REC call otherwise it is by zero set by default during declaration

        for(auto it : graph[node]){
            if(!Vis[it]){
                if(dfs_method(it , graph , Vis , pathVis , check)){
                    check[node]=0; //it will not be the part of answer bcoz it is the part(conncted to) of some cycle detected somewhere during REC call
                    return true; //i.e cycle is detected
                }
            }

            else if(pathVis[it]){ //cycle is detected for this particular node
                check[node]=0;
                return true;
            }
        }

        check[node]=1;

        //backTrack
        pathVis[node]=0;

        return false; //cycle not detected for this node i.e this node is the safeNode

    }

    void bfs_method(int& V , vector<vector<int>>& REVgraph , vector<int> indegree , vector<int>& safeNodes){

        queue<int> q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNodes.push_back(node); //it will be the part of the answer bcoz only those nodes will be pushed into the q having indegree 0

            for(auto it : REVgraph[node]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        //------1------dfs_method

        int V=graph.size();
        vector<int> Vis(V ,0);
        vector<int> pathVis(V ,0);
        vector<int> check(V,0);

        for(int i=0;i<V;i++){
            if(!Vis[i]){
                dfs_method(i , graph , Vis , pathVis , check);
            }
        }

        vector<int> safeNodes;

        for(int i=0;i<V;i++){
            if(check[i]==1){
                safeNodes.push_back(i);
            }
        }

        return safeNodes;



        //------2------bfs method----->more space complexity

        // int V=graph.size();
        // vector<int> indegree(V,0);

        // //reverse the edges

        // vector<vector<int>> REVgraph(V);

        // for(int i=0;i<graph.size();i++){
        //     for(auto it : graph[i]){
        //         REVgraph[it].push_back(i);
        //         indegree[i]++;
        //     }
        // }

        // vector<int> safeNodes;

        // bfs_method(V , REVgraph , indegree , safeNodes);

        // return safeNodes;
    }
};