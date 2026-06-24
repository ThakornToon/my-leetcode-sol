class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // สร้าง prefix XOR matrix
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        vector<int> values;
        values.reserve(m * n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int top = (i > 0) ? prefix[i-1][j] : 0;
                int left = (j > 0) ? prefix[i][j-1] : 0;
                int diag = (i > 0 && j > 0) ? prefix[i-1][j-1] : 0;
                
                prefix[i][j] = matrix[i][j] ^ top ^ left ^ diag;
                values.push_back(prefix[i][j]);
            }
        }
        
        // เรียงลำดับจากมากไปน้อย
        sort(values.begin(), values.end(), greater<int>());
        
        return values[k - 1];
    }
};