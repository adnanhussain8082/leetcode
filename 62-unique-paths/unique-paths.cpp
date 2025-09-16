// class Solution {  //recursion
// private:
//     int f(int row , int col){
//         //base case
//         if(row==0 and col==0) return 1;

//         if(row < 0 or col < 0) return 0;

//         int cnt=0;
//         int up = f(row-1 , col);
//         int down = f(row , col-1);

//         cnt += up+down;

//         return cnt;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         return f(m-1 , n-1);
//     }
// };


// class Solution {  //memoization--one way
// private:
//     int f(int row , int col , vector<vector<int>>& dp){
//         //base case
//         if(row==0 and col==0) return 1;

//         if(row < 0 or col < 0) return 0;

//         if(dp[row][col] != -1) return dp[row][col];

//         int cnt=0;
//         int up = f(row-1 , col , dp);
//         int down = f(row , col-1 , dp);

//         cnt += up+down;

//         return dp[row][col] = cnt;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m , vector<int>(n,-1));
//         return f(m-1 , n-1 , dp);
//     }
// };



// class Solution {  //memoization--other way
// private:
//     int f(int row , int col , int rows , int cols , vector<vector<int>>& dp){
//         //base case
//         if(row==rows and col==cols) return 1;

//         if(dp[row][col]!=-1) return dp[row][col];
//         int cnt=0;
        
//         if(row+1 <= rows){
//             cnt += f(row+1 , col , rows , cols , dp);
//         }
//         if(col+1 <= cols){
//             cnt += f(row , col+1 , rows , cols , dp);
//         }

//         return dp[row][col] = cnt;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m , vector<int>(n,-1));

//         return f(0 , 0 , m-1 , n-1 , dp);
//     }
// };


// class Solution {  //tabulation
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m , vector<int>(n,0));

//         for(int row=0;row<m;row++){
//             for(int col=0;col<n;col++){
//                 if(row==0 and col==0){
//                     dp[row][col]=1;
//                     continue;
//                 }

//                 int up=0;
//                 int left=0;

//                 if(row > 0){
//                     up = dp[row-1][col];
//                 }

//                 if(col > 0){
//                     left = dp[row][col-1];
//                 }

//                 dp[row][col]=up+left;
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };


class Solution {  //space optimization
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);

        for(int row=0;row<m;row++){
            vector<int> temp(n,0);
            for(int col=0;col<n;col++){
                if(row==0 and col==0){
                    temp[col]=1;
                    continue;
                }

                int up=0;
                int left=0;

                if(row > 0){
                    up = prev[col];
                }

                if(col > 0){
                    left = temp[col-1];
                }

                temp[col]=up+left;
            }

            prev = temp;
        }
        return prev[n-1];
    }
};