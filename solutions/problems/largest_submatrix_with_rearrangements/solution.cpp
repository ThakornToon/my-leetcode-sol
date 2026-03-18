class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        
        // คำนวณความสูงสะสม
        for (int i = 0; i < m; i++) {
            // อัปเดตความสูงจากแถวก่อนหน้า
            for (int j = 0; j < n; j++) {
                if (i > 0 && matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
            
            // เรียงลำดับความสูงในแถวนี้
            vector<int> heights = matrix[i];
            sort(heights.begin(), heights.end(), greater<int>());
            
            // คำนวณพื้นที่
            for (int j = 0; j < n; j++) {
                if (heights[j] == 0) break;
                maxArea = max(maxArea, heights[j] * (j + 1));
            }
        }
        
        return maxArea;
    }
};