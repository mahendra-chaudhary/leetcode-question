class Solution {
public:
        void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number
                }
            }
        }
        return true; // solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false; // check row
            if (board[i][col] == c) return false; // check col
            int r = 3 * (row / 3) + i / 3;
            int d = 3 * (col / 3) + i % 3;
            if (board[r][d] == c) return false; // check 3x3 box
        }
        return true;
        
    }
};