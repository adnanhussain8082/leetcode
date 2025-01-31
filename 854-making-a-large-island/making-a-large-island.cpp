class DisjointSet {
public: 
    vector<int> parent, size; 
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
            size[i] = 1; 
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
private:
    bool isValid(int& newr , int& newc , int& n){
        return newr>=0 && newr<n && newc>=0 && newc<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        //step1:
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};

                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];

                    if(isValid(newr , newc , n) && grid[newr][newc]==1){
                        int nodeNo=row*n + col;
                        int adjnodeNo=newr*n+newc;

                        ds.unionBySize(nodeNo,adjnodeNo);
                    }
                }
            }
        }

        //step2:
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};

                set<int> components; //stores the unique value
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];

                if(isValid(newr , newc , n)){
                    if(grid[newr][newc]==1){
                        int nodeNo=newr*n+newc;
                        components.insert(ds.findUPar(nodeNo));
                    }
                }

                int sizeTotal=0;
                for(auto it : components){
                    sizeTotal += ds.size[it];
                }

                mx=max(mx , sizeTotal+1);
            }
        }

        }

        //edge case : if all the cells already have 1
        for(int cellno=0;cellno<n*n;cellno++){
            mx=max(mx , ds.size[ds.findUPar(cellno)]);
        }

        return mx;
    }
};