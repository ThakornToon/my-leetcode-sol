class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        vector<vector<int>> adj(n);  // ตารางว่าเดินจากโหนดไหนไปไหนได้บ้าง
        vector<int> degree(n, 0);  // ดีกรีของโหนดต่างๆ
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        // BFS จากใบ deg = 1 ขึ้นไป
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        // ทำขึ้นไปที่ละ level จนกว่าจะเจอ root โดย MHT จะมีแค่ 1 หรือ 2 เท่านั้น
        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            int sz = q.size();
            remaining_nodes -= sz;
            // ขึ้นไปที่โหนด level ก่อนหน้า
            for (int i = 0; i < sz; ++i) {
                int leaf = q.front();
                q.pop();
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};