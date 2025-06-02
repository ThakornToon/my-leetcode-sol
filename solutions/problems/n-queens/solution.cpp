class Solution {
private:
    bool check(vector<string> &board, int n, int row, int col) {
        for (int i = 1; i <= row ; i++) {
            if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') {
                return false;
            }
            if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q') {
                return false;
            }
            if (row - i >= 0 && board[row - i][col] == 'Q') {
                return false;
            }
        }
        return true;
    } 
    void backtrack(vector<vector<string>> &res, vector<string> &board, int n, int row) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(board, n, row, i)) {
                board[row][i] = 'Q';
                backtrack(res, board, n, row + 1);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, n, 0);
        return res;
    }
};