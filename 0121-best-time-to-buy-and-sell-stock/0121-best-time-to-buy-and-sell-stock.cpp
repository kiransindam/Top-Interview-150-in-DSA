class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX; // Track the lowest price seen so far
        int max_profit = 0;      // Track the maximum profit we can make
        
        for (int price : prices) {
            // If we find a new lowest price, update our buying point
            if (price < min_price) {
                min_price = price;
            } 
            // Otherwise, check if selling today gives us a better profit
            else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }
        
        return max_profit;
    }
};