/*
Pattern
1 1
1 #
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0);
        int prev = 0;
        int side = 0;
        
        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                int temp = heights[i + 1];
                if (row[i] == '1') {
                    heights[i + 1] = min({heights[i], heights[i + 1], prev}) + 1;
                    side = max(side, heights[i + 1]);   
                }
                else {
                    heights[i + 1] = 0;
                }
                prev = temp;
            }
        }
        
        return side * side;
    }
};