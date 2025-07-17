class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // เก็บตำแหน่งเริ่มต้นของ 0 ทั้งหมด
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // ทิศทางสำหรับเคลื่อนที่ (ขึ้น, ล่าง, ซ้าย, ขวา)
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (auto dir : dirs) {
                int x = curr.first + dir.first;
                int y = curr.second + dir.second;

                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (dist[x][y] > dist[curr.first][curr.second] + 1) {
                        dist[x][y] = dist[curr.first][curr.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return dist;
    }
};