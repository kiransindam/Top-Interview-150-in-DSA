class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_end = 0; // The end of the current jump's window
        int farthest = 0;    // The farthest index we can reach in the next jump
        int n = nums.size();
        
        // We don't need to jump from the last element, so we stop at n - 2
        for (int i = 0; i < n - 1; i++) {
            // Update the farthest we can reach from the current position
            farthest = max(farthest, i + nums[i]);
            
            // If we have reached the end of the current jump's window
            if (i == current_end) {
                jumps++;               // We are forced to make another jump
                current_end = farthest; // Our new window extends to the farthest we saw
                
                // Optimization: if we can already reach or pass the last index, we are done!
                if (current_end >= n - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};