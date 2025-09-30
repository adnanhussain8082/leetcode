class Solution {
private:
    int f(int ind , int amount , vector<int>& arr , vector<vector<int>>& dp){
        //base case
        if(ind==0){
            if(amount%arr[ind]==0){
                return amount/arr[ind];
            }
            else{
                return 1e9;
            }
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int not_take = f(ind-1 , amount , arr , dp);
        int take=1e9;
        if(arr[ind]<=amount){
            take = 1 + f(ind , amount-arr[ind] , arr , dp);
        }

        return dp[ind][amount] = min(take , not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int m=coins.size();
        vector<vector<int>> dp(m , vector<int>(amount+1 , -1));
        int ans = f(m-1 , amount , coins , dp);

        if(ans==1e9) return -1;
        return ans;
    }
};