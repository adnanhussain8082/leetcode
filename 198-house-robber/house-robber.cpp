// User function template for C++
// class Solution { //recursion
//   private:
//     int f(int ind , vector<int>& arr){
//         //base case
//         if(ind < 0) return 0;
        
//         int pick = arr[ind] + f(ind-2 , arr);
//         int not_pick = f(ind-1 , arr);
        
//         return max(pick , not_pick);
//     }
//   public:
//     // calculate the maximum sum with out adjacent
//     int findMaxSum(vector<int>& arr) {
//         // code here
//         int n=arr.size();
//         return f(n-1,arr);
        
//     }
// };

// class Solution { //memoization
//   private:
//     int f(int ind , vector<int>& arr , vector<int>& dp){
//         //base case
//         if(ind < 0) return 0;
        
//         if(dp[ind]!=-1) return dp[ind];
//         int pick = arr[ind] + f(ind-2 , arr , dp);
//         int not_pick = f(ind-1 , arr , dp);
        
//         return dp[ind] = max(pick , not_pick);
//     }
//   public:
//     // calculate the maximum sum with out adjacent
//     int findMaxSum(vector<int>& arr) {
//         // code here
//         int n=arr.size();
//         vector<int> dp(n,-1);
        
//         return f(n-1,arr,dp);
        
//     }
// };


// class Solution { //tabulation
//   public:
//     // calculate the maximum sum with out adjacent
//     int findMaxSum(vector<int>& arr) {
//         // code here
//         int n=arr.size();
//         vector<int> dp(n,-1);
        
//         //base case
//         dp[0]=arr[0];
//         // dp[1]=arr[1];
        
//         for(int i=1;i<n;i++){
//             int pick = arr[i];
//             if(i>1) pick += dp[i-2];
//             int not_pick = dp[i-1];
            
//             dp[i] = max(pick , not_pick);
//         }
        
//         return dp[n-1];
        
//     }
// };


class Solution { //space optimization
  public:
    // calculate the maximum sum with out adjacent
    int rob(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        //base cases
        int prev=arr[0];  //prev===dp[ind-1]
        int prev2=0;      //prev2===dp[ind-2]
        
        
        for(int i=1;i<n;i++){
            int pick = arr[i] + prev2;
            int not_pick = prev;
            
            int curr_i = max(pick , not_pick);
            
            prev2=prev;
            prev=curr_i;
        }
        
        return prev;
        
    }
};

