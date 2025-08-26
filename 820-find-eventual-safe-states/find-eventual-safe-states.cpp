class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();

        vector<vector<int>> revGraph(v);

        for(int i=0;i<v;i++){
            for(auto& it : graph[i]){
                revGraph[it].push_back(i);
            }
        }

        vector<int> inorder(v,0);

        for(int i=0;i<v;i++){
            for(auto& it : revGraph[i]){
                inorder[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<v;i++){
            if(inorder[i]==0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int& ne : revGraph[node]){
                inorder[ne]--;
                if(inorder[ne]==0) q.push(ne);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};