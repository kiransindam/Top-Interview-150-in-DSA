class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Track seen numbers in each row, column, and sub-box
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                
                // Skip empty cells
                if (c == '.') continue;
                
                int num = c - '1'; // Convert '1'-'9' to 0-8
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                // Check if this number was already seen in the same row, column, or box
                if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                    return false; // Duplicate found!
                }
                
                // Mark this number as seen
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[boxIndex][num] = true;
            }
        }
        
        return true; // No duplicates found
    }
};