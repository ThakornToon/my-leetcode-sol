class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int res = INT_MIN;
        for (int r1 = 1; r1 <= rows; ++r1) {
            for (int c1 = 1; c1 <= cols; ++c1) {
                for (int r2 = r1; r2 <= rows; ++r2) {
                    for (int c2 = c1; c2 <= cols; ++c2) {
                        int sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
                        if (sum <= k && sum > res) {
                            res = sum;
                            if (res == k) return k;
                        }
                    }
                }
            }
        }
        return res;
    }
};
