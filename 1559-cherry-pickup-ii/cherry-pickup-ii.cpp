// class Solution {   //recursion
// private:
//     int f(int row , int col1 , int col2 , vector<vector<int>>& grid){
//         int m=grid[0].size();
//         //out of index check
//         if(col1<0 or col1>=m or col2<0 or col2>=m){
//             return -1e9;
//         }

//         //base case
//         if(row==grid.size()-1){
//             if(col1==col2) return grid[row][col1];
//             else return grid[row][col1] + grid[row][col2];
//         }

//         int maxi=INT_MIN;

//         for(int d1=-1;d1<=1;d1++){
//             for(int d2=-1;d2<=1;d2++){
//                 int ans;
//                 if(col1==col2){
//                     ans = grid[row][col1] + f(row+1 , col1+d1 , col2+d2 , grid);
//                 }
//                 else{
//                     ans = grid[row][col1] + grid[row][col2] + f(row+1 , col1+d1 , col2+d2 , grid);
//                 }
//                 maxi = max(maxi , ans);
//             }
//         }
//         return maxi;
//     }
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         return f(0 , 0 , grid[0].size()-1 , grid);
//     }
// };








class Solution {  //memoization
private:
    int f(int row , int col1 , int col2 , vector<vector<int>>& grid ,  vector<vector<vector<int>>>& dp){
        int m=grid[0].size();
        //out of index check
        if(col1<0 or col1>=m or col2<0 or col2>=m){
            return -1e9;
        }

        //base case
        if(row==grid.size()-1){
            if(col1==col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }

        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];

        int maxi=INT_MIN;

        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                int ans;
                if(col1==col2){
                    ans = grid[row][col1] + f(row+1 , col1+d1 , col2+d2 , grid , dp);
                }
                else{
                    ans = grid[row][col1] + grid[row][col2] + f(row+1 , col1+d1 , col2+d2 , grid , dp);
                }
                maxi = max(maxi , ans);
            }
        }
        return dp[row][col1][col2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size() , n=grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n , vector<int>(n,-1)));
        return f(0 , 0 , grid[0].size()-1 , grid , dp);
    }
};