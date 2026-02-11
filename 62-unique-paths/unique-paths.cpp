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
    int f(int m , int n , vector<vector<int>>& dp){
        //base cases
        if(m==0 and n==0) return 1;
        if(m<0 or n<0) return 0;

        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n] = f(m-1 , n , dp) + f(m , n-1 , dp);
    }

public:
    int uniquePaths(int m, int n) {
        
        // return f(m-1,n-1);

        //memo
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return f(m-1,n-1,dp);

    }
};