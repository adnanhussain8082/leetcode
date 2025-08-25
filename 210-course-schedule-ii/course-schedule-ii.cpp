class Solution {
private:
    void topoSort(int& V , vector<int>& topo , vector<vector<int>>& adjList){
        vector<int> inorder(V, 0);

        for(int i=0;i<V;i++){
            for(auto& it : adjList[i]){
                inorder[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<V;i++){
            if(inorder[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int ne : adjList[node]){
                inorder[ne]--;
                if(inorder[ne]==0){
                    q.push(ne);
                }
            }

            topo.push_back(node);
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        
        //adjList
        vector<vector<int>> adjList(V);
        for(auto& it : prerequisites){
            adjList[it[1]].push_back(it[0]);
        }

        vector<int> topo;

        topoSort(V , topo , adjList);

        if(topo.size() == V){
            return topo;
        }

        return {};
    }
};