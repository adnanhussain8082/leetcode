class Solution {
private:
    void dfs(int node , vector<vector<int>>& edges , vector<bool>& vis , vector<vector<int>>& adjList , int& vertexCount , int& edgeCount){
        vis[node]=true;
        vertexCount++;
        edgeCount += adjList[node].size();

        for(const auto& ne : adjList[node]){
            if(!vis[ne]){
                dfs(ne , edges , vis , adjList , vertexCount , edgeCount);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adjList(n);

       for(const auto& edge : edges){
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
       }

       int completeComponents=0;
       vector<bool> vis(n,0);

       for(int node=0;node<n;node++){
        int vertexCount=0 , edgeCount=0;
        dfs(node , edges , vis , adjList , vertexCount , edgeCount);

        completeComponents += vertexCount*(vertexCount-1) == edgeCount;
        // No need to divide by 2 because edgeCount is already twice the actual edges (each edge is counted twice in an undirected graph).
       }

       return completeComponents;
    }
};