// class Solution {  //recursion
// private:
//     int f(int row , int col , int rows , int cols){
//         //base case
//         if(row==rows and col==cols) return 1;

//         int cnt=0;
//         if(row+1 <= rows){
//             cnt += f(row+1 , col , rows , cols);
//         }
//         if(col+1 <= cols){
//             cnt += f(row , col+1 , rows , cols);
//         }

//         return cnt;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         return f(0 , 0 , m-1 , n-1);
//     }
// };



class Solution {  //memoization
private:
    int f(int row , int col , int rows , int cols , vector<vector<int>>& dp){
        //base case
        if(row==rows and col==cols) return 1;

        if(dp[row][col]!=-1) return dp[row][col];
        int cnt=0;
        
        if(row+1 <= rows){
            cnt += f(row+1 , col , rows , cols , dp);
        }
        if(col+1 <= cols){
            cnt += f(row , col+1 , rows , cols , dp);
        }

        return dp[row][col] = cnt;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n,-1));

        return f(0 , 0 , m-1 , n-1 , dp);
    }
};