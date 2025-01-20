class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size() , n=mat[0].size();
        //arr.size == m*n given

        unordered_map<int,pair<int,int>> hashMap;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                hashMap[mat[i][j]] = {i,j};
            }
        }

        vector<int> rowCount(m,n);
        vector<int> colCount(n,m);

        for(int k=0;k<arr.size();k++){
            auto[i,j]=hashMap[arr[k]];

            rowCount[i]--;
            colCount[j]--;

            if(rowCount[i]==0 || colCount[j]==0){
                return k;
            }
        }

        return -1;
    }
};