class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        // เก็บ effort ดีที่สุดที่ตำแหน่งต่างๆขณะนั้น
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // น้อยไปมากตาม (effort, x, y) ที่ตำแหน่งต่างๆ
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        
        // คิดที่ตำแหน่ง effort น้อยๆก่อน
        while (!pq.empty()) {
            auto [effort, x, y] = pq.top();
            pq.pop();
            
            // effort ดีกว่าเดิมค่อยคิดใหม่ที่ตำแหน่งนั้น
            if (effort > dist[x][y]) continue;

            // ถึงจุดหมาย
            if (x == m - 1 && y == n - 1) return effort;
            
            // ไปทั้งสี่ทิศ
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // ตรวจสอบขอบเขต
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));

                    // ไปแล้ว effort ดีกว่าเดิม
                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};