class Solution {
    void solve5(int& n , int& m , string& s1 , string& s2 , vector<vector<int>>& dp){
        //base case equivalent
        for(int i=0;i<=n;i++) dp[i][0];
        for(int j=0;j<=m;j++) dp[0][j];

        //nested loops
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size() , m=s2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

        solve5(n , m , s1 , s2 , dp);

        int i=n , j=m;
        string ans="";

        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];  //bcoz this char will be common to both strings , so only adding once to ans
                i-- , j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }

        while(i>0){
            ans+=s1[i-1] , i--;
        }
        while(j>0){
            ans+=s2[j-1] , j--;
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};