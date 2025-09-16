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


class Solution {  //memoization
private:
    int f(int row , int col , vector<vector<int>>& dp){
        //base case
        if(row==0 and col==0) return 1;

        if(row < 0 or col < 0) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int cnt=0;
        int up = f(row-1 , col , dp);
        int down = f(row , col-1 , dp);

        cnt += up+down;

        return dp[row][col] = cnt;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return f(m-1 , n-1 , dp);
    }
};



// class Solution {  //memoization
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


