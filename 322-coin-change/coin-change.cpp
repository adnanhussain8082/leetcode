// class Solution {
// private:
//     int f(int ind , int amount , vector<int>& arr , vector<vector<int>>& dp){
//         //base case
//         if(ind==0){
//             if(amount%arr[ind]==0){
//                 return amount/arr[ind];
//             }
//             else{
//                 return 1e9;
//             }
//         }

//         if(dp[ind][amount]!=-1) return dp[ind][amount];

//         int not_take = f(ind-1 , amount , arr , dp);
//         int take=1e9;
//         if(arr[ind]<=amount){
//             take = 1 + f(ind , amount-arr[ind] , arr , dp);
//         }

//         return dp[ind][amount] = min(take , not_take);
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int m=coins.size();
//         vector<vector<int>> dp(m , vector<int>(amount+1 , -1));
//         int ans = f(m-1 , amount , coins , dp);

//         if(ans==1e9) return -1;
//         return ans;
//     }
// };



// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int m=coins.size();
//         vector<vector<int>> dp(m , vector<int>(amount+1 , 0));
        
//         for(int i=0;i<=amount;i++){
//             if(i%coins[0]==0){
//                 dp[0][i] = i/coins[0];
//             }
//             else{
//                 dp[0][i] = 1e9;
//             }
//         }

//         for(int i=1;i<m;i++){
//             for(int amt=0;amt<=amount;amt++){
                
//                 int not_take = dp[i-1][amt];
//                 int take=1e9;
//                 if(coins[i]<=amt){
//                     take = 1 + dp[i][amt-coins[i]];
//                 }

//                 dp[i][amt] = min(take,not_take);
//             }
//         }

//         if(dp[m-1][amount]==1e9) return -1;
//         return dp[m-1][amount];
//     }
// };





class Solution {   
public:
    int coinChange(vector<int>& coins, int amount) {
        int m=coins.size();
        
        vector<int> prev(amount+1,0);
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                prev[i] = i/coins[0];
            }
            else{
                prev[i] = 1e9;
            }
        }

        for(int i=1;i<m;i++){
            vector<int> temp(amount+1,0);
            for(int amt=0;amt<=amount;amt++){
                
                int not_take = prev[amt];
                int take=1e9;
                if(coins[i]<=amt){
                    take = 1 + temp[amt-coins[i]];
                }

                temp[amt] = min(take,not_take);
            }
            prev=temp;
        }

        if(prev[amount]==1e9) return -1;
        return prev[amount];
    }
};