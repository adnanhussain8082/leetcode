class Solution {
private:
    int bfs(int currNode , int k ,  vector<vector<int>>& gr , int& n){
        vector<int> visited(n,0);
        queue<int> q;

        q.push(currNode);
        visited[currNode]=1;

        int dist=0;
        int cnt=0;

        while(!q.empty() && dist<=k){ //bfs
            int sz=q.size();

            while(sz--){  //level wise traversal for each level
                int node = q.front();
                q.pop();

                cnt++;

                for(int ne : gr[node]){
                    if(!visited[ne]){
                        visited[ne]=1;
                        q.push(ne);
                    }
                }
            }
            dist++;  //increase the dist as one level has been explored 
        }
        return cnt;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;

        vector<vector<int>> gr1(n);
        vector<vector<int>> gr2(m);

        for(auto& it : edges1){
            gr1[it[0]].push_back(it[1]);
            gr1[it[1]].push_back(it[0]);
        }

        for(auto& it : edges2){
            gr2[it[0]].push_back(it[1]);
            gr2[it[1]].push_back(it[0]);
        }

        vector<int> ans(n,0);
        int cnt=0;

        for(int i=0;i<n;i++){
            cnt = bfs(i , k , gr1 , n);
            ans[i] = cnt;
        }

        int goldenNodeDisCnt=0;

        for(int i=0;i<m;i++){
            cnt = bfs(i , k-1 , gr2 , m);
            if (cnt > goldenNodeDisCnt) {
                goldenNodeDisCnt = cnt;
            }
        }

        for(int i=0;i<n;i++){
            ans[i] += goldenNodeDisCnt;
        }

        return ans;
    }
};