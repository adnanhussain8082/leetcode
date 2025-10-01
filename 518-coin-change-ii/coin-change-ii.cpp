// class Solution {
// private:
//     int f(int ind , int amount , vector<int>& coins){
//         //base cases
//         if(ind==0){
//             if(coins[ind]<=amount){
//                 return (amount%coins[ind])==0;
//             }
//             else{
//                 return 0;
//             }
//         }

//         if(amount==0){
//             return 1;
//         }

//         int not_take = f(ind-1 , amount , coins);
//         int take=0;
//         if(coins[ind]<=amount){
//             take = f(ind , amount-coins[ind] , coins);
//         }

//         return take+not_take;
//     }
// public:
//     int change(int amount, vector<int>& coins) {
//         int m=coins.size();
//         return f(m-1 , amount , coins);

//     }
// };




class Solution {
private:
    int f(int ind , int amount , vector<int>& coins , vector<vector<int>>& dp){
        //base cases
        if(amount==0){
            return 1;
        }

        if(ind==0){
            return (amount%coins[ind])==0;
        }

        //memoization check
        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int not_take = f(ind-1 , amount , coins , dp);
        int take=0;
        if(coins[ind]<=amount){
            take = f(ind , amount-coins[ind] , coins , dp);
        }

        return dp[ind][amount] = take+not_take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int m=coins.size();
        vector<vector<int>> dp(m,vector<int>(amount+1,-1));
        return f(m-1 , amount , coins , dp);
        
    }
};