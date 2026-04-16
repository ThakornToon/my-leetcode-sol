class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // หาค่าสูงสุดในแต่ละคอลัมน์
        vector<int> colMax(n, INT_MIN);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < m; i++) {
            // หาค่าต่ำสุดในแถว i
            int rowMin = *min_element(matrix[i].begin(), matrix[i].end());
            
            // หาตำแหน่งของค่าต่ำสุด
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == rowMin && rowMin == colMax[j]) {
                    result.push_back(rowMin);
                }
            }
        }
        
        return result;
    }
};