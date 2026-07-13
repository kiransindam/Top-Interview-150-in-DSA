class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // Calculate the area of the current container
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;
            
            // Update the maximum water found so far
            max_water = max(max_water, area);
            
            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};