class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        vector<int> result(n);
        
        // ใช้ map แทน unordered_map เพื่อให้ access เร็วขึ้น
        unordered_map<int, vector<int>> graph;
        graph.reserve(n * 2);
        
        for (auto& pair : adjacentPairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        
        // หาจุดเริ่มต้น
        int start = 0;
        for (auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                start = node;
                break;
            }
        }
        
        // สร้าง path
        int prev = start;
        int curr = graph[start][0];
        result[0] = start;
        
        for (int i = 1; i < n; i++) {
            result[i] = curr;
            
            // หา node ถัดไป
            int next = 0;
            for (int neighbor : graph[curr]) {
                if (neighbor != prev) {
                    next = neighbor;
                    break;
                }
            }
            
            prev = curr;
            curr = next;
        }
        
        return result;
    }
};