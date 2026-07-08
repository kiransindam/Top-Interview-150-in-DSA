class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int water = 0;
        
        while (left < right) {
            // If the left bar is shorter, the left side is the bottleneck
            if (height[left] < height[right]) {
                // If current bar is taller than left_max, update left_max (no water trapped here)
                if (height[left] >= left_max) {
                    left_max = height[left];
                } 
                // Otherwise, the water level is left_max, and we trap the difference
                else {
                    water += left_max - height[left];
                }
                left++;
            } 
            // If the right bar is shorter (or equal), the right side is the bottleneck
            else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    water += right_max - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
};