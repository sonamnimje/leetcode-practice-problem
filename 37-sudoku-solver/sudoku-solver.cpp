class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, r, c, ch)) {
                            board[r][c] = ch;

                            if (solve(board)) return true;

                            // backtrack
                            board[r][c] = '.';
                        }
                    }
                    return false; // no valid digit found
                }
            }
        }
        return true; // all cells filled
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            // check row
            if (board[row][i] == ch) return false;
            // check col
            if (board[i][col] == ch) return false;
            // check 3x3 sub-box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == ch) return false;
        }
        return true;
    }
};
