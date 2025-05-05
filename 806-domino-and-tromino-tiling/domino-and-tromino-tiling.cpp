int mod=1e9+7;
class Solution {
private: 
    //method1:REC
    int solve(int n){
        if(n==1 || n==2){
            return n;
        }
        if(n==3){
            return 5;
        }

        return (2*solve(n-1)%mod + solve(n-3)%mod)%mod;
    }

    //method2:Memoization
    int solve(int n , vector<int>& dp){
        if(n==1 || n==2){
            return n;
        }
        if(n==3){
            return 5;
        }

        //memoization check
        if(dp[n]!=-1) return dp[n];

        return dp[n] = (2*solve(n-1 , dp)%mod + solve(n-3 , dp)%mod)%mod;
    }
public:
    int numTilings(int n) {
        
        //method1 : REC
        // return solve(n);

        //method2 : Memoization
        vector<int> dp(1001 , -1);
        return solve(n , dp);
    }
};