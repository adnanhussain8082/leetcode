// class Solution {   recursion
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




// class Solution {   memoization
// private:
//     int f(int ind , int amount , vector<int>& coins , vector<vector<int>>& dp){
//         //base cases
//         if(amount==0){
//             return 1;
//         }

//         if(ind==0){
//             return (amount%coins[ind])==0;
//         }

//         //memoization check
//         if(dp[ind][amount]!=-1) return dp[ind][amount];

//         int not_take = f(ind-1 , amount , coins , dp);
//         int take=0;
//         if(coins[ind]<=amount){
//             take = f(ind , amount-coins[ind] , coins , dp);
//         }

//         return dp[ind][amount] = take+not_take;
//     }
// public:
//     int change(int amount, vector<int>& coins) {
//         int m=coins.size();
//         vector<vector<int>> dp(m,vector<int>(amount+1,-1));
//         return f(m-1 , amount , coins , dp);
        
//     }
// };






// class Solution {  
// public:
//     int change(int amount, vector<int>& coins) {
//         int m=coins.size();
//         vector<vector<int>> dp(m,vector<int>(amount+1,0));

//         for(int i=0;i<m;i++){
//             dp[i][0] = 1;
//         }

//         for(int amt=1;amt<=amount;amt++){
//             dp[0][amt] = (amt%coins[0]==0) ? 1 : 0;
//         }
        
//         for(int ind=1;ind<m;ind++){
//             for(int amt=1;amt<=amount;amt++){

//                 int not_take = dp[ind-1][amt];
//                 int take=0;
//                 if(coins[ind]<=amt){
//                     take = dp[ind][amt-coins[ind]];
//                 }

//                 dp[ind][amt] = take+not_take;
//             }
//         }

//         return dp[m-1][amount];
//     }
// };



class Solution {  
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        
        vector<unsigned int> prev(amount+1, 0);

        // prev[0] = 1;

        for(int amt=0; amt<=amount; amt++){
            prev[amt] = (amt % coins[0] == 0) ? 1 : 0;
        }
        
        for(int ind=1; ind<m; ind++){
            // vector<unsigned int> temp(amount+1, 0);
            // temp[0] = 1;
            for(int amt=0; amt<=amount; amt++){
                unsigned int not_take = prev[amt];
                unsigned int take = 0;
                if(coins[ind] <= amt){
                    take = prev[amt - coins[ind]];
                }
                prev[amt] = take + not_take;
            }
            // prev = temp;
        }

        return prev[amount];
    }
};
