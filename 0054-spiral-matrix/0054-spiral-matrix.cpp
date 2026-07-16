class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse right along the top row
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++; // Shrink top boundary
            
            // Traverse down along the right column
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Shrink right boundary
            
            // Traverse left along the bottom row (if still valid)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--; // Shrink bottom boundary
            }
            
            // Traverse up along the left column (if still valid)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Shrink left boundary
            }
        }
        
        return result;
    }
};