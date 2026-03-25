class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long>> prefix(m + 1, vector<long long>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + 
                               prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        long long total = prefix[m][n];
        if (total % 2 != 0) return false;
        long long target = total / 2;
        
        // ตรวจสอบแนวตั้ง
        for (int j = 1; j < n; j++) {
            if (prefix[m][j] == target) return true;
        }
        
        // ตรวจสอบแนวนอน
        for (int i = 1; i < m; i++) {
            if (prefix[i][n] == target) return true;
        }
        
        return false;
    }
};