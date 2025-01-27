class Solution {
private:
    void topoSort(int& V , vector<vector<int>> adj , vector<int> indegree , vector<unordered_set<int>>& nodePrerequisites){
        queue<int> q;

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto& adjNode : adj[node]){
                nodePrerequisites[adjNode].insert(node);
                for(auto& prereq : nodePrerequisites[node]){
                    nodePrerequisites[adjNode].insert(prereq);
                }
                if(--indegree[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int V=numCourses;
        int n=prerequisites.size();

        vector<vector<int>> adj(V);

        //derive the adjacency list
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        //derive the indegree vector
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        //now initialise a container to store a node's father , grandfather , greatgrandfather annd soon(kinnda toposort but generational)
        vector<unordered_set<int>> nodePrerequisites(V); 

        topoSort(V , adj , indegree , nodePrerequisites);

        vector<bool> ans;
        
        for(auto& query : queries){
            ans.push_back(nodePrerequisites[query[0]].count(query[1]));
        }
        return ans;
    }
};