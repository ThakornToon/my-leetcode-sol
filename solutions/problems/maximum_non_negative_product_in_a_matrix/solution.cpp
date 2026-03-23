class Solution {
private:
    const int MOD = 1000000007;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<long long> dpMax(n, LLONG_MIN);
        vector<long long> dpMin(n, LLONG_MAX);
        
        dpMax[0] = dpMin[0] = grid[0][0];
        
        // เติมแถวแรก
        for (int j = 1; j < n; j++) {
            dpMax[j] = dpMax[j-1] * grid[0][j];
            dpMin[j] = dpMin[j-1] * grid[0][j];
        }
        
        // DP ทีละแถว
        for (int i = 1; i < m; i++) {
            // คำนวณ column 0 ก่อน
            long long newMax = dpMax[0] * grid[i][0];
            long long newMin = dpMin[0] * grid[i][0];
            dpMax[0] = newMax;
            dpMin[0] = newMin;
            
            for (int j = 1; j < n; j++) {
                int val = grid[i][j];
                
                long long fromTopMax = dpMax[j] * val;
                long long fromTopMin = dpMin[j] * val;
                long long fromLeftMax = dpMax[j-1] * val;
                long long fromLeftMin = dpMin[j-1] * val;
                
                newMax = max({fromTopMax, fromTopMin, fromLeftMax, fromLeftMin});
                newMin = min({fromTopMax, fromTopMin, fromLeftMax, fromLeftMin});
                
                dpMax[j] = newMax;
                dpMin[j] = newMin;
            }
        }
        
        return (dpMax[n-1] < 0) ? -1 : (int)(dpMax[n-1] % MOD);
    }
};