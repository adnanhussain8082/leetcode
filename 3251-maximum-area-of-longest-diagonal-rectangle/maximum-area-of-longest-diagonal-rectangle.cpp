class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        // vector<int> sdi()
        int maxArea=0;
        float maxDiag=0;

        for(auto& it : dimensions){
            float diag=sqrt(it[0]*it[0] + it[1]*it[1]);

            if(diag>maxDiag){
                maxDiag = diag;
                maxArea = it[0]*it[1];
            }
            else if(diag==maxDiag){
                maxArea = max(maxArea , (it[0]*it[1]));
            }
        }

        return maxArea;
    }
};