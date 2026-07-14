class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int current_sum = 0;
        int min_length = INT_MAX;
        
        // Expand the window by moving right pointer
        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];
            
            // When we have a valid window (sum >= target), try to shrink it
            while (current_sum >= target) {
                // Update the minimum length found so far
                min_length = min(min_length, right - left + 1);
                
                // Shrink the window from the left
                current_sum -= nums[left];
                left++;
            }
        }
        
        // If min_length was never updated, no valid subarray exists
        return min_length == INT_MAX ? 0 : min_length;
    }
};