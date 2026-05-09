class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;
        
        for (int layer = 0; layer < layers; layer++) {
            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;
            
            // extract layer elements in order
            vector<int> elements;
            
            // top row
            for (int j = left; j <= right; j++) {
                elements.push_back(grid[top][j]);
            }
            // right column
            for (int i = top + 1; i <= bottom; i++) {
                elements.push_back(grid[i][right]);
            }
            // bottom row
            for (int j = right - 1; j >= left; j--) {
                elements.push_back(grid[bottom][j]);
            }
            // left column
            for (int i = bottom - 1; i > top; i--) {
                elements.push_back(grid[i][left]);
            }
            
            // rotate
            int perimeter = elements.size();
            int shift = k % perimeter;
            // จุดเริ่มต้นของช่วงที่จะหมุน, จุดที่จะกลายเป็น element แรกหลังหมุน, จุดสิ้นสุดของช่วง
            rotate(elements.begin(), elements.begin() + shift, elements.end());
            
            // put back
            int idx = 0;
            for (int j = left; j <= right; j++) {
                grid[top][j] = elements[idx++];
            }
            for (int i = top + 1; i <= bottom; i++) {
                grid[i][right] = elements[idx++];
            }
            for (int j = right - 1; j >= left; j--) {
                grid[bottom][j] = elements[idx++];
            }
            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = elements[idx++];
            }
        }
        
        return grid;
    }
};