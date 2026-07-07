class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1); // Initialize output array with 1s
        
        // Pass 1: Calculate Prefix Products (Left to Right)
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;       // Store the product of everything to the left
            prefix *= nums[i];        // Update prefix for the next element
        }
        
        // Pass 2: Calculate Suffix Products (Right to Left) and multiply into answer
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;      // Multiply by the product of everything to the right
            suffix *= nums[i];        // Update suffix for the next element
        }
        
        return answer;
    }
};