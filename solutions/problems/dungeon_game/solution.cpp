class Solution {
public:
    void go(vector<vector<int>>& dungeon, vector<vector<int>>& mem, int row, int col, int prev) {
        if (row < 0 || col < 0) {
            return;
        }

        if (prev + dungeon[row][col] >= 0 && mem[row][col] != 0) {
            mem[row][col] = 0;
        } else if (prev + dungeon[row][col] < 0 && prev + dungeon[row][col] > mem[row][col]) {
            mem[row][col] = prev + dungeon[row][col];
        } else {
            return;
        }
        go(dungeon, mem, row - 1, col, mem[row][col]);
        go(dungeon, mem, row, col - 1, mem[row][col]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> mem(dungeon.size(), vector<int>(dungeon[0].size(), INT_MIN));
        go(dungeon, mem, dungeon.size() - 1, dungeon[0].size() - 1, 0);
        return (mem[0][0] * -1) + 1;
    }
};