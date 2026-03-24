class Solution {
public:
    const long long MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, 1));
        
        // forward pass: product of all elements before current
        long long prod = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = (result[i][j] * prod) % MOD;
                prod = (prod * (grid[i][j] % MOD)) % MOD;
            }
        }
        
        // backward pass: multiply by product of all elements after current
        prod = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                result[i][j] = (result[i][j] * prod) % MOD;
                prod = (prod * (grid[i][j] % MOD)) % MOD;
            }
        }
        
        return result;
    }
};