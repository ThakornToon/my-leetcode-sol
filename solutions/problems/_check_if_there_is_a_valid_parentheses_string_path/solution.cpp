class Solution {
private:
    bool visited[100][100][101];  // [row][col][balance]
    int m, n;

    bool dfs(int r, int c, int bal, vector<vector<char>>& grid) {
        // อัปเดต balance ตามเครื่องหมายในช่องปัจจุบัน
        bal += (grid[r][c] == '(' ? 1 : -1);

        // วงเล็บปิดเกิน หรือ วงเล็บเปิดเกินจนจำนวนก้าวที่เหลือไม่พอปิด
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (bal < 0 || bal > remaining_steps) {
            return false;
        }

        // ถึงปลายทาง ตรวจสอบว่า balance กลับมาเป็น 0 หรือไม่
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        // หากเคยเข้าสู่สถานะนี้แล้ว ไม่ต้องทำซ้ำ
        if (visited[r][c][bal]) {
            return false;
        }
        visited[r][c][bal] = true;

        // เดินลง หรือ เดินขวา
        if (r + 1 < m && dfs(r + 1, c, bal, grid)) return true;
        if (c + 1 < n && dfs(r, c + 1, bal, grid)) return true;

        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // เส้นทางความยาวคี่ หรือหัว/ท้ายไม่ถูกต้อง จะไม่มีทาง valid
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        memset(visited, 0, sizeof(visited));
        return dfs(0, 0, 0, grid);
    }
};