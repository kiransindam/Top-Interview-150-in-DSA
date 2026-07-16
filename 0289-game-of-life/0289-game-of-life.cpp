class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // 8 possible neighbor directions
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        // First pass: mark state transitions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                // Count live neighbors
                for (auto& dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        // Count as live if it's 1 OR -1 (was alive, marked to die)
                        if (board[ni][nj] == 1 || board[ni][nj] == -1) {
                            liveNeighbors++;
                        }
                    }
                }
                
                // Apply rules
                if (board[i][j] == 1) {
                    // Live cell
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = -1; // Dies (under/over-population)
                    }
                    // If 2 or 3 neighbors, stays 1 (no change needed)
                } else {
                    // Dead cell
                    if (liveNeighbors == 3) {
                        board[i][j] = 2; // Becomes alive (reproduction)
                    }
                    // Otherwise stays 0 (no change needed)
                }
            }
        }
        
        // Second pass: convert markers to final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0; // Was alive, now dead
                } else if (board[i][j] == 2) {
                    board[i][j] = 1; // Was dead, now alive
                }
                // 0 and 1 remain unchanged
            }
        }
    }
};