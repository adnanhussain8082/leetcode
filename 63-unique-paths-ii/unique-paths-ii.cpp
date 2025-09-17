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




// class Solution {  //memoization
// private:
//     int f(int row , int col, vector<vector<int>>& obstacleGrid ,  vector<vector<int>>& dp){
//         //base cases
//         if(row==0 and col==0 and obstacleGrid[row][col]==0) return 1;
//         if(row<0 or col<0) return 0;
//         if(obstacleGrid[row][col]==1) return 0;

//         if(dp[row][col]!=-1) return dp[row][col];

//         int count=0;
//         int up = f(row-1 , col , obstacleGrid , dp);
//         int left = f(row , col-1 , obstacleGrid , dp);

//         count = up+left;

//         return dp[row][col] = count;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();

//         vector<vector<int>> dp(m , vector<int>(n,-1));
//         return f(m-1 , n-1, obstacleGrid , dp);
//     }
// };




class Solution {  //tabulation
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>> dp(m , vector<int>(n,0));

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                //base case
                if(row==0 and col==0 and obstacleGrid[row][col]==0){
                    dp[row][col]=1;
                    continue;
                }

                if(obstacleGrid[row][col]!=1){ //no obstacle at the cell

                    int right=0;
                    int down=0;

                    if(row>0){
                        down = dp[row-1][col];
                    }

                    if(col>0){
                        right = dp[row][col-1];
                    }

                    dp[row][col] = right+down;
                }
            }
        }

        return dp[m-1][n-1];
    }
};