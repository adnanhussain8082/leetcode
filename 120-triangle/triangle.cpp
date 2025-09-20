// class Solution {    //recursion(here top down special case)
// private:
//     int f(int row , int col , vector<vector<int>>& triangle){
//         //base case
//         if(row == triangle.size()-1){   //last row we return
//             return triangle[row][col];
//         }

//         int down = triangle[row][col] + f(row+1 , col , triangle);
//         int diagonal = triangle[row][col] + f(row+1 , col+1 , triangle);

//         return min(down , diagonal);

//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return f(0,0,triangle);
//     }
// };



// class Solution {    //memoization
// private:
//     int f(int row , int col , vector<vector<int>>& triangle , vector<vector<int>>& dp){
//         if(dp[row][col]!=-1) return dp[row][col];

//         //base case
//         if(row == triangle.size()-1){   //last row we return
//             return triangle[row][col];
//         }


//         int down = triangle[row][col] + f(row+1 , col , triangle , dp);
//         int diagonal = triangle[row][col] + f(row+1 , col+1 , triangle , dp);

//         return dp[row][col] = min(down , diagonal);

//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
//   
//         vector<vector<int>> dp(m,vector<int>(m,-1)); bcoz "n" has diff values for diff rows
//         return f(0,0,triangle,dp);
//     }
// };






// class Solution {    //tabulation

// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
//         int n=triangle[0].size();
//         vector<vector<int>> dp(m,vector<int>(m,-1));

//         //base case
//         for(int i=0;i<triangle[m-1].size();i++){
//             dp[m-1][i] = triangle[m-1][i];
//         }

//         for(int i=m-2;i>=0;i--){
//             for(int j=0;j<triangle[i].size();j++){

//                 int up = triangle[i][j] + dp[i+1][j];
//                 int diagonal = triangle[i][j] + dp[i+1][j+1];

//                 dp[i][j] = min(up,diagonal);
//             }
//         }
//         return dp[0][0];
//     }
// };






class Solution {    //space optimization

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<int> next(m,0);

        //base case
        for(int i=0;i<triangle[m-1].size();i++){
            next[i] = triangle[m-1][i];
        }

        for(int i=m-2;i>=0;i--){
            vector<int> temp(m,0);
            for(int j=0;j<triangle[i].size();j++){

                int up = triangle[i][j] + next[j];
                int diagonal = triangle[i][j] + next[j+1];

                temp[j] = min(up,diagonal);
            }
            next = temp;
        }
        return next[0];
    }
};