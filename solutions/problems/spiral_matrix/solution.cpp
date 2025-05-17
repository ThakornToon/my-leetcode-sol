class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top_row = 0;
        int bottom_row = matrix.size()-1;
        int left_col = 0;
        int right_col = matrix[0].size()-1;
        int x = 0;
        int y = 0;
        vector<int> res;
        int i = 0;
        while(i < matrix.size() * matrix[0].size()) {
            x = left_col;
            y = top_row;
            for(; x<=right_col; x++) {
                res.push_back(matrix[y][x]);
                i++;
            }
            if(i == matrix.size() * matrix[0].size()) {
                break;
            }
            x--;
            y++;
            for(; y<=bottom_row; y++) {
                res.push_back(matrix[y][x]);
                i++;
            }
            if(i == matrix.size() * matrix[0].size()) {
                break;
            }
            y--;
            x--;
            for(; x>=left_col; x--) {
                res.push_back(matrix[y][x]);
                i++;
            }
            if(i == matrix.size() * matrix[0].size()) {
                break;
            }
            x++;
            y--;
            for(; y>top_row; y--) {
                res.push_back(matrix[y][x]);
                i++;
            }
            top_row++;
            bottom_row--;
            left_col++;
            right_col--;
        }
        return res;
    }
};