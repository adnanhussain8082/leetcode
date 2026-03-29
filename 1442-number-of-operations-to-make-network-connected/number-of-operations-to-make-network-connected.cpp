class DisjointSet {
public: 
    vector<int> parent, size; 
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1 , 1); 
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
            // size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ExtraEdges=0;
        for(auto it : connections){
            int u=it[0];
            int v=it[1];

            if(ds.findUPar(u)==ds.findUPar(v)){
                ExtraEdges++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int NumComp=0; //NumComp = no of components
        //now traverse thru parent vector to find the no of ultimate parents which inturn gives us no of components
        for(int i=0;i<n;i++){
            if(i == ds.parent[i]){
                NumComp++;
            }
        }

        int ans=NumComp-1;

        if(ExtraEdges >= ans){
            return ans;
        }

        return -1;
    }
};