class Solution {
private:
    //rec
    // int f(int m , int n){
    //     //base cases
    //     if(m==0 and n==0) return 1;
    //     if(m<0 or n<0) return 0;

    //     return f(m-1 , n) + f(m , n-1);
    // }

    //memo
    // int f(int m , int n , vector<vector<int>>& dp){
    //     //base cases
    //     if(m==0 and n==0) return 1;
    //     if(m<0 or n<0) return 0;

    //     if(dp[m][n]!=-1) return dp[m][n];

    //     return dp[m][n] = f(m-1 , n , dp) + f(m , n-1 , dp);
    // }

    //tab
    // int f(int& m , int& n){
    //     vector<vector<int>> dp(m , vector<int>(n,1));

    //     for(int i=1;i<m;i++){
    //         for(int j=1;j<n;j++){
    //             dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //         }
    //     }

    //     return dp[m-1][n-1];
    // }

    //SO
    int f(int& m , int& n){
        vector<int> prev(n,1);

        for(int i=1;i<m;i++){
            vector<int> curr(n,1);
            for(int j=1;j<n;j++){
                curr[j] = prev[j] + curr[j-1];
            }
            prev=curr;
        }

        return prev[n-1];
    }





public:
    int uniquePaths(int m, int n) {
        
        // return f(m-1,n-1);

        //memo
        // vector<vector<int>> dp(m , vector<int>(n,-1));
        // return f(m-1,n-1,dp);

        //tab
        // return f(m , n);

        //SO
        return f(m,n);

    }
};