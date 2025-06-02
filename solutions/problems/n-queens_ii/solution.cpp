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
    void backtrack(vector<string> &board, int n, int row, int &count) {
        if (row == n) {
            count++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(board, n, row, i)) {
                board[row][i] = 'Q';
                backtrack(board, n, row + 1, count);
                board[row][i] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        backtrack(board, n, 0, count);
        return count;
    }
};