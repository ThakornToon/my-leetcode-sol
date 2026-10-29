class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);  // 0: ยังไม่ระบาย, 1: สี A, -1: สี B

        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) continue;  // ระบายแล้ว

            queue<int> q;
            q.push(i);
            color[i] = 1;

            // BFS
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                // ดูโหนดข้างเคียงห้ามสีชน
                for (int neighbor : graph[curr]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[curr];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[curr]) {
                        return false;  // สีชนกัน แปลว่าไม่ใช่ Bipartite
                    }
                }
            }
        }
        return true;
    }
};