constexpr int MAXN = 100005;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjList(n);

        vector<int> indegree(n,0);

        for(const auto& it : invocations){
            adjList[it[0]].push_back(it[1]);
            indegree[it[1]]++;

        }

        bitset<MAXN> sus;

        sus.set(k);

        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adjList[u]){
                indegree[v]--;

                if(!sus.test(v)){
                    sus.set(v);
                    q.push(v);
                }
            }
        }

        bool canRemoveAll = true;
        vector<int> rem;

        for(int i=0;i<n;i++){
            if(sus.test(i) and indegree[i] > 0){
                canRemoveAll = false;
                break;
            }
            else if(!sus.test(i)){
                rem.push_back(i);
            }
        }

        if(!canRemoveAll){
            vector<int> allnodes(n);
            iota(allnodes.begin(),allnodes.end(),0);
            return allnodes;
        }

        return rem;
    }
};