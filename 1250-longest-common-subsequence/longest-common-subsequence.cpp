// class Solution { recursion
// private:
//     int f(int i , int j , string& t1 , string& t2){
//         //base case
//         if(i<0 or j<0) return 0;

//         int ans=0;

//         if(t1[i]==t2[j]){
//             ans = 1 + f(i-1 , j-1 , t1 , t2);
//         }
//         else{
//             ans = max(f(i-1,j,t1,t2) , f(i,j-1,t1,t2));
//         }

//         return ans;
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size() , n=text2.size();

//         return f(m-1,n-1,text1,text2);
//     }
// };





// class Solution {   //recursion with shifted index
// private:
//     int f(int i , int j , string& t1 , string& t2){
//         //base case
//         if(i==0 or j==0) return 0;


//         if(t1[i-1]==t2[j-1]){
//             return 1 + f(i-1 , j-1 , t1 , t2);
//         }
        
//         return max(f(i-1,j,t1,t2) , f(i,j-1,t1,t2));

//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size() , n=text2.size();

//         return f(m,n,text1,text2);
//     }
// };



// class Solution {   //memoization with shifted index(shifted index is required in case of tabulation cuz 2d matrix can't have negative index as is seen in the base case of simple recursion)
// private:
//     int f(int i , int j , string& t1 , string& t2 , vector<vector<int>>& dp){
//         //base case
//         if(i==0 or j==0) return 0;

//         if(dp[i][j]!=-1) return dp[i][j];

//         if(t1[i-1]==t2[j-1]){
//             return dp[i][j] = 1 + f(i-1 , j-1 , t1 , t2 , dp);
//         }
        
//         return dp[i][j] = max(f(i-1,j,t1,t2,dp) , f(i,j-1,t1,t2,dp));

//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size() , n=text2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

//         return f(m,n,text1,text2,dp);
//     }
// };




// class Solution {   //tabulation with shifted index(shifted index is required in case of tabulation cuz 2d matrix can't have negative index as is seen in the base case of simple recursion)

// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size() , n=text2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));

//         for(int i=1;i<m+1;i++){
//             for(int j=1;j<n+1;j++){
//                 int ans=0;
//                 if(text1[i-1]==text2[j-1]){  //shifted index
//                     ans += 1 + dp[i-1][j-1];
//                 }
//                 else{
//                     ans += max(dp[i-1][j] , dp[i][j-1]);
//                 }

//                 dp[i][j] = ans;
//             }
//         }

//         return dp[m][n];
//     }
// };





class Solution {   //space optmization

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size() , n=text2.size();
        
        vector<int> prev(n+1,0);

        // prev[0]=0;

        // for(int j=0;j<n+1;j++){
        //     prev[j] = 0;
        // }

        for(int i=1;i<m+1;i++){
            vector<int> temp(n+1,0);
            for(int j=1;j<n+1;j++){
                int ans=0;
                if(text1[i-1]==text2[j-1]){  //shifted index
                    ans += 1 + prev[j-1];
                }
                else{
                    ans += max(prev[j] , temp[j-1]);
                }

                temp[j] = ans;
            }
            prev=temp;
        }

        return prev[n];
    }
};