class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        board[row][col] = 'R';
        if (row > 0 && board[row - 1][col] == 'O') {
            dfs(row - 1, col, board);
        }
        if (row < board.size() - 1 && board[row + 1][col] == 'O') {
            dfs(row + 1, col, board);
        }
        if (col > 0 && board[row][col - 1] == 'O') {
            dfs(row, col - 1, board);
        }
        if (col < board[0].size() - 1 && board[row][col + 1] == 'O') {
            dfs(row, col + 1, board);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3) {
            return;
        }
        for (int row = 0; row < board.size(); row++) {
            if (board[row][0] == 'O') {
                dfs(row, 0, board);
            }
            if (board[row][board[0].size() - 1] == 'O') {
                dfs(row, board[0].size() - 1, board);
            }
        }
        for (int col = 1; col < board[0].size() - 1; col++) {
            if (board[0][col] == 'O') {
                dfs(0, col, board);
            }
            if (board[board.size() - 1][col] == 'O') {
                dfs(board.size() - 1, col, board);
            }
        }
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
                else if (board[row][col] == 'R') {
                    board[row][col] = 'O';
                }
            }
        }
    }
};