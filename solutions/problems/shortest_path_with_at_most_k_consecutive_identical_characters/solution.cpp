class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (k < 1) return -1;

        // สร้าง Adjacency list ของ u -> ค่า (v, w) ทั้งหมด
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // dist[u][count] เก็บ cost น้อยที่สุดในการมาถึงโหนด u ด้วยจำนวนตัวอักษรติดกัน count
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, std::vector<int>(k + 1, INF));

        // Priority queue น้อยไปมากเก็บ tuple ของ (cost, u, count)
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // Dijkstra เลือกเส้นทางที่ cost น้อยสุดก่อน
        while (!pq.empty()) {
            auto [cost, u, count] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return cost;
            }

            // cost เส้นทางปัจจุบันแย่กว่าที่เราเคยคิด
            if (cost > dist[u][count]) {
                continue;
            }

            // ลองเดินไปในทุกเส้นทาง
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                int next_count = (labels[u] == labels[v]) ? (count + 1) : 1;

                if (next_count <= k) {
                    int new_cost = cost + w;
                    if (new_cost < dist[v][next_count]) {
                        dist[v][next_count] = new_cost;
                        pq.push({new_cost, v, next_count});
                    }
                }
            }
        }

        return -1;
    }
};