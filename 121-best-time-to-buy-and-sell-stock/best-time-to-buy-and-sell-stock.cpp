class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=prices[0] , profit=0;

        for(int i=1;i<prices.size();i++){
            profit = max(profit , prices[i]-cost);
            cost = min(cost , prices[i]);
        }

        return profit;
    }
};