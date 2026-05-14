class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> allEdges = cuts;
        allEdges.push_back(0);
        allEdges.push_back(n);
        sort(allEdges.begin(), allEdges.end());
        
        int m = allEdges.size();
        vector<vector<int>> memo(m, vector<int>(m, -1));
        
        return dfs(allEdges, 0, m - 1, memo);
    }
    
    int dfs(vector<int>& edges, int i, int j, vector<vector<int>>& memo) {
        if (i + 1 >= j) return 0;  // ไม่มีตำแหน่งให้ตัด
        if (memo[i][j] != -1) return memo[i][j];
        
        int result = INT_MAX;
        // ตัวแบ่ง k ระหว่าง i และ j
        for (int k = i + 1; k < j; k++) {
            int cost = dfs(edges, i, k, memo) + dfs(edges, k, j, memo) + (edges[j] - edges[i]);
            result = min(result, cost);
        }
        
        return memo[i][j] = result;
    }
};