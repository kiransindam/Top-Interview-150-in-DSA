class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        // Start from day 1 and compare with the previous day
        for (int i = 1; i < prices.size(); i++) {
            // If the price went up, we "sell" and collect the profit
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        
        return max_profit;
    }
};