class DisjointSet{
    public:

    vector<int> size , parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    int minEdges=0;
    void UnionBySize(int& u , int& v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){
           return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ExtraEdges=0;

        for(auto& it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                ExtraEdges++;
            }
            else{
                ds.UnionBySize(u,v);
            }
        }

        int nc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                nc++;
            }
        }

        int ans=nc-1;

        if(ExtraEdges >= ans){
            return ans;
        }

        return -1;
    }
};