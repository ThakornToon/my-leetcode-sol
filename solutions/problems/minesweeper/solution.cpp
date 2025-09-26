class Solution {
public:
    void adj(vector<vector<char>>& board, int x, int y) {
        if (x >= board.size() || x < 0 || y >= board[0].size() || y < 0) {
            return;
        }
        int row = board.size();
        int col = board[0].size();
        if (board[x][y] == 'B' || isdigit(board[x][y])) {
            return;
        } else if (board[x][y] == 'M') {
            return;
        } else {
            int boom = 0;
            if (x - 1 >= 0 && board[x - 1][y] == 'M') {
                boom++;
            }
            if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'M') {
                boom++;
            }
            if (x - 1 >= 0 && y + 1 < col && board[x - 1][y + 1] == 'M') {
                boom++;
            }
            if (x + 1 < row && board[x + 1][y] == 'M') {
                boom++;
            }
            if (x + 1 < row && y - 1 >= 0 && board[x + 1][y - 1] == 'M') {
                boom++;
            }
            if (x + 1 < row && y + 1 < col && board[x + 1][y + 1] == 'M') {
                boom++;
            }
            if (y - 1 >= 0 && board[x][y - 1] == 'M') {
                boom++;
            }
            if (y + 1 < col && board[x][y + 1] == 'M') {
                boom++;
            }

            if (boom != 0) {
                board[x][y] = '0' + boom;
                return;
            } else {
                board[x][y] = 'B';
                adj(board, x - 1, y - 1);
                adj(board, x - 1, y);
                adj(board, x - 1, y + 1);
                adj(board, x, y - 1);
                adj(board, x, y + 1);
                adj(board, x + 1, y - 1);
                adj(board, x + 1, y);
                adj(board, x + 1, y + 1);
                return;
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = board.size();
        int col = board[0].size();
        int y = click[1];
        int x = click[0];
        if (board[x][y] == 'B' || isdigit(board[x][y])) {
            return board;
        } else if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        } else {
            int boom = 0;
            if (x - 1 >= 0 && board[x - 1][y] == 'M') {
                boom++;
            }
            if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'M') {
                boom++;
            }
            if (x - 1 >= 0 && y + 1 < col && board[x - 1][y + 1] == 'M') {
                boom++;
            }
            if (x + 1 < row && board[x + 1][y] == 'M') {
                boom++;
            }
            if (x + 1 < row && y - 1 >= 0 && board[x + 1][y - 1] == 'M') {
                boom++;
            }
            if (x + 1 < row && y + 1 < col && board[x + 1][y + 1] == 'M') {
                boom++;
            }
            if (y - 1 >= 0 && board[x][y - 1] == 'M') {
                boom++;
            }
            if (y + 1 < col && board[x][y + 1] == 'M') {
                boom++;
            }

            if (boom != 0) {
                board[x][y] = '0' + boom;
                return board;
            } else {
                board[x][y] = 'B';
                adj(board, x - 1, y - 1);
                adj(board, x - 1, y);
                adj(board, x - 1, y + 1);
                adj(board, x, y - 1);
                adj(board, x, y + 1);
                adj(board, x + 1, y - 1);
                adj(board, x + 1, y);
                adj(board, x + 1, y + 1);
                return board;
            }
        }
    }
};