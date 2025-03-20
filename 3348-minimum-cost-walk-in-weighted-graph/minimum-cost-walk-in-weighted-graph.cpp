class Solution {
private:
    void dfs(int node , vector<vector<int>>& gr , vector<int>& vis , int compNumb , unordered_map<int,int>& nodeToComp){
        vis[node]=1;
        nodeToComp[node]=compNumb;
        for(auto& ne : gr[node]){
            if(!vis[ne]){
                dfs(ne , gr , vis , compNumb , nodeToComp);
            }
        }
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       vector<vector<int>> gr(n);

       for(auto& it : edges){
        gr[it[0]].push_back(it[1]);
        gr[it[1]].push_back(it[0]);
       }

       int compNumb=1;
       vector<int> vis(n,0);
       unordered_map<int,int> nodeToComp; //it will store that to which component every vertex/node belongs so no need to use union

       for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i , gr , vis , compNumb , nodeToComp);
            compNumb++;
        }
       }

       vector<int> compANDscore(n , pow(2,31)-1);
       for(auto& it : edges){
        int u=it[0] , v=it[1] , wt=it[2];
        int uComp = nodeToComp[u];

        compANDscore[uComp] = compANDscore[uComp] & wt;   
       }

       vector<int> ans;

       for(auto& it : query){
        if(it[0]==it[1]){
            ans.push_back(0);
        }

        else if(nodeToComp[it[0]] == nodeToComp[it[1]]){
            ans.push_back(compANDscore[nodeToComp[it[0]]]);
        }

        else{
            ans.push_back(-1);
        }
       }

       return ans;
    }
};