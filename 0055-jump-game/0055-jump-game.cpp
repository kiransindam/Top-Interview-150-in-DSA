class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the current index is beyond our maximum reach, we are stuck
            if (i > max_reach) {
                return false;
            }
            
            // Update the furthest index we can reach from the current position
            max_reach = max(max_reach, i + nums[i]);
            
            // Early exit: if we can already reach or pass the last index, we win!
            if (max_reach >= n - 1) {
                return true;
            }
        }
        
        return true; // Fallback (though the early exit handles it)
    }
};