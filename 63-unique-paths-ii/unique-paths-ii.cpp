// class Solution {  recursion
// private:
//     int f(int row , int col, vector<vector<int>>& obstacleGrid){
//         //base cases
//         if(row==0 and col==0) return 1;
//         if(row<0 or col<0) return 0;
//         if(obstacleGrid[row][col]==1) return 0;

//         int count=0;
//         int up = f(row-1 , col , obstacleGrid);
//         int left = f(row , col-1 , obstacleGrid);

//         count = up+left;

//         return count;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();

//         return f(m-1 , n-1, obstacleGrid);
//     }
// };




class Solution {  //memoization
private:
    int f(int row , int col, vector<vector<int>>& obstacleGrid ,  vector<vector<int>>& dp){
        //base cases
        if(row==0 and col==0 and obstacleGrid[row][col]==0) return 1;
        if(row<0 or col<0) return 0;
        if(obstacleGrid[row][col]==1) return 0;

        if(dp[row][col]!=-1) return dp[row][col];

        int count=0;
        int up = f(row-1 , col , obstacleGrid , dp);
        int left = f(row , col-1 , obstacleGrid , dp);

        count = up+left;

        return dp[row][col] = count;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>> dp(m , vector<int>(n,-1));
        return f(m-1 , n-1, obstacleGrid , dp);
    }
};