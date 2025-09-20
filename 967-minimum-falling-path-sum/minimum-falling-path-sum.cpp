// class Solution {   //recursion
// private:
//     int f(int row , int col , vector<vector<int>>& matrix){
//         //base case
//         if(row == matrix.size()-1){ //bcoz we can reach any one of the last row cells
//             return matrix[row][col];
//         }
//         int leftDiag=1e9;
//         int rightDiag=1e9;

//         if(col-1>=0){
//             leftDiag = matrix[row][col] + f(row+1 , col-1 , matrix);
//         }
//         if(col+1<=matrix[0].size()-1){
//             rightDiag = matrix[row][col] + f(row+1 , col+1 , matrix);
//         }
//         int down = matrix[row][col] + f(row+1 , col , matrix); //no need to check for this case, it will always be inside bounds

//         return min({leftDiag,down,rightDiag});
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int ans=1e9;

//         for(int j=0;j<m;j++){
//             ans = min(ans , f(0 , j , matrix));
//         }
//         return ans;
//     }
// };






// class Solution {    //memoization
// private:
//     int f(int row , int col , vector<vector<int>>& matrix , vector<vector<int>>& dp){
//         //base case
//         if(row == matrix.size()-1){ //bcoz we can reach any one of the last row cells
//             return matrix[row][col];
//         }

//         if(dp[row][col]!=-1) return dp[row][col];

//         int leftDiag=1e9;
//         int rightDiag=1e9;

//         if(col-1>=0){
//             leftDiag = matrix[row][col] + f(row+1 , col-1 , matrix , dp);
//         }
//         if(col+1<=matrix[0].size()-1){
//             rightDiag = matrix[row][col] + f(row+1 , col+1 , matrix , dp);
//         }
//         int down = matrix[row][col] + f(row+1 , col , matrix , dp); //no need to check for this case, it will always be inside bounds

//         return dp[row][col] = min({leftDiag,down,rightDiag});
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int ans=1e9;

//         vector<vector<int>> dp(m , vector<int>(m,-1));

//         for(int j=0;j<m;j++){
//             ans = min(ans , f(0 , j , matrix , dp));
//         }
//         return ans;
//     }
// };



class Solution {    //tabulation
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int ans=1e9;

        vector<vector<int>> dp(m , vector<int>(m,0));
        vector<int> answers(m,0);

        for(int i=0;i<m;i++){
            dp[m-1][i] = matrix[m-1][i];
        }

        for(int k=0;k<m;k++){
            int start=dp[m-1][k];

            for(int row=m-2;row>=0;row--){
                for(int col=0;col<=m-1;col++){

                    int leftDiag=1e9 , rightDiag=1e9;

                    if(col-1>=0){
                        leftDiag = matrix[row][col] + dp[row+1][col-1];
                    }
                    if(col+1<=m-1){
                        rightDiag = matrix[row][col] + dp[row+1][col+1];
                    }
                    int down = matrix[row][col] + dp[row+1][col]; //no need to check for this case, it will always be inside bounds

                    dp[row][col] = min({leftDiag,down,rightDiag});
                }
            }

            int anss=1e9;
            for(int i=0;i<m;i++){
                anss = min(anss , dp[0][i]);
            }

            answers[k]=anss;

        }

        for(int i=0;i<m;i++){
            ans = min(ans , answers[i]);
        }
        return ans;
    }
};