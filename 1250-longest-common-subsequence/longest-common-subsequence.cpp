// class Solution { 
// private:
//     int f(int i , int j , string& text1 , string& text2){
//         //base case
//         if(i<0 or j<0) return 0;

//         if(text1[i]==text2[j]){
//             return 1 + f(i-1 , j-1 , text1 , text2);
//         }

//         return max(f(i-1 , j , text1 , text2) , f(i , j-1 , text1 , text2));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         return f(text1.size()-1 , text2.size()-1 , text1 , text2);
//     }
// };







// class Solution { //shifted index
// private:
//     int f(int i , int j , string& text1 , string& text2){
//         //base case
//         if(i==0 or j==0) return 0;

//         if(text1[i-1]==text2[j-1]){
//             return 1 + f(i-1 , j-1 , text1 , text2);
//         }

//         return max(f(i-1 , j , text1 , text2) , f(i , j-1 , text1 , text2));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         return f(text1.size() , text2.size() , text1 , text2);
//     }
// };







// class Solution { //shifted index and memorization
// private:
//     int f(int i , int j , string& text1 , string& text2 , vector<vector<int>>& dp){
//         //base case
//         if(i==0 or j==0) return 0;

//         if(dp[i][j]!=-1) return dp[i][j];

//         if(text1[i-1]==text2[j-1]){
//             return dp[i][j] = 1 + f(i-1 , j-1 , text1 , text2 , dp);
//         }

//         return dp[i][j] = max(f(i-1 , j , text1 , text2 , dp) , f(i , j-1 , text1 , text2 , dp));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size() , n=text2.size();
//         vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
//         return f(m , n , text1 , text2 , dp);
//     }
// };






class Solution { //tabulation

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size() , n=text2.size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
};