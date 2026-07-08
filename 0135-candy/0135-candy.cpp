class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // Step 1: Give every child at least 1 candy
        vector<int> candies(n, 1);
        
        // Step 2: Left-to-Right pass
        // Satisfies the rule: "higher rating than left neighbor -> more candies"
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Step 3: Right-to-Left pass
        // Satisfies the rule: "higher rating than right neighbor -> more candies"
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                // We take the max to ensure we don't violate the left-neighbor rule we just established
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // Step 4: Sum up all the candies
        int total_candies = 0;
        for (int c : candies) {
            total_candies += c;
        }
        
        return total_candies;
    }
};