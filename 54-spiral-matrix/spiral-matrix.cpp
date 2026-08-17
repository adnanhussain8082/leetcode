class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();

        //varaibles
        int startingRow = 0;
        int endingRow = m-1;
        int startingCol = 0;
        int endingCol = n-1;

        int count=0;
        while(startingRow<=endingRow && startingCol<=endingCol){
            //printing starting row
            for(int i=startingCol;i<=endingCol;i++){
                ans.push_back(matrix[startingRow][i]);
            }
            startingRow++;

            for(int i=startingRow;i<=endingRow;i++){
                ans.push_back(matrix[i][endingCol]);
            }
            endingCol--;

            if(startingRow<=endingRow){
                for(int i=endingCol;i>=startingCol;i--){
                ans.push_back(matrix[endingRow][i]);
            }
            endingRow--;
            }

            if(startingCol<=endingCol){
               for(int i=endingRow;i>=startingRow;i--){
                ans.push_back(matrix[i][startingCol]);
            }
            startingCol++; 
            }
        }
            return ans;
    }
};