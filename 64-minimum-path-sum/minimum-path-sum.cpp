// class Solution { //recursion
// private:
//     int f(int row , int col , vector<vector<int>>& grid){
//         //base case
//         if(row==0 and col==0) return grid[0][0];

//         int up=INT_MAX;
//         int left=INT_MAX;

//         if(row-1>=0) up = grid[row][col] + f(row-1 , col , grid);

//         if(col-1>=0) left = grid[row][col] + f(row , col-1 , grid);

//         return min(up , left);

//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();

//         return f(m-1 , n-1 , grid);
//     }
// };





// class Solution { //memoization
// private:
//     int f(int row , int col , vector<vector<int>>& grid , vector<vector<int>>& dp){
//         //base case
//         if(row==0 and col==0) return grid[0][0];

//         if(dp[row][col]!=-1) return dp[row][col];
//         int up=INT_MAX;
//         int left=INT_MAX;

//         if(row-1>=0) up = grid[row][col] + f(row-1 , col , grid , dp);

//         if(col-1>=0) left = grid[row][col] + f(row , col-1 , grid , dp);

//         return dp[row][col] = min(up , left);

//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();

//         vector<vector<int>> dp(m , vector<int>(n,-1));

//         return f(m-1 , n-1 , grid , dp);
//     }
// };




class Solution { //tabulation
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m , vector<int>(n,0));

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 and col==0){
                    dp[0][0] = grid[0][0];
                    continue;
                }

                int right=1e9;
                int down=1e9;

                if(row>0){
                    down = grid[row][col] + dp[row-1][col];
                }

                if(col>0){
                    right = grid[row][col] + dp[row][col-1];
                }

                dp[row][col] = min(right , down);
            }
        }

        return dp[m-1][n-1];
    }
};