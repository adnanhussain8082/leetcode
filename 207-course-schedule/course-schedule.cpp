// class Solution {
// private:
//     void topoSort(int& V , vector<int> adj[] , vector<int>& topo){
//         vector<int> indegree(V , 0);
        
//         //since it is a problem similar to DAG(directed acyclic graph) so using topoSort algo here
//         //deriving the indegree array from adjacency list for kahn's algo(bfs method for topo sort)
// 	    for(int i=0;i<V;i++){
// 	        for(auto it : adj[i]){
// 	            indegree[it]++;
// 	        }
// 	    }
	    
//         queue<int> q;
//         for(int i=0;i<V;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
        
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             topo.push_back(node); //storing answer(topo sort) , those verticies which are stuck in a cycle will never be a part of this vector
            
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0){
//                     q.push(it);
//                 }
//             }
//         }
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         //numCourses can be treated as verticies of the graph

//         int n=prerequisites.size();
//         int V=numCourses;

//         //deriving the adjacency list from the prerequisites
//         vector<int> adj[V];
//         for(int i=0;i<n;i++){
//             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
//         }

//         vector<int> topo;
//         topoSort(V , adj , topo);
//         if(topo.size()==numCourses){ //i.e there is no cycle
//             return true;
//         }

//         return false;
//     }
// };



//some modification---we don't even need to store the topoSort elements,
//we can keep a counter instead

class Solution {
private:
    int topoSort(int& V ,  vector<vector<int>>& adjList){
        vector<int> indegree(V,0);
        int topoCount=0;

        for(int i=0;i<V;i++){
            for(auto& it : adjList[i]){
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            topoCount++;

            for(int ne : adjList[node]){
                indegree[ne]--;
                if(indegree[ne]==0) q.push(ne);
            }
            
        }

        return topoCount;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        int n=prerequisites.size();

        //adj list
        vector<vector<int>> adjList(V);
        for(auto& it : prerequisites){
            adjList[it[1]].push_back(it[0]);
        }

        int topoCount = topoSort(V , adjList);

        return topoCount==V;
    }
};