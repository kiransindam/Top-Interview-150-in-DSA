class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if only 1 row, no zigzag pattern
        if (numRows == 1) return s;
        
        // Create an array of strings, one for each row
        vector<string> rows(min(numRows, (int)s.length()));
        
        int currentRow = 0;
        bool goingDown = false; // We start by going down, but will flip immediately
        
        // Iterate through each character in the input string
        for (char c : s) {
            rows[currentRow] += c; // Add character to the current row
            
            // Change direction if we hit the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to the next row based on current direction
            currentRow += goingDown ? 1 : -1;
        }
        
        // Concatenate all rows into the final result
        string result = "";
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};