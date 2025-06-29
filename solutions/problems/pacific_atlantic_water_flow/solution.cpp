class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int prevHeight) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || visited[i][j] || heights[i][j] < prevHeight) {
            return; 
        }
        
        visited[i][j] = true; // ถ้าพื้นที่อยู่ในขอบเขตและมีความสูงมากกว่าก่อนหน้านี้
        
        // ตรวจสอบ 4 ทิศทางว่าไหลไปไดไหม
        dfs(heights, visited, i+1, j, heights[i][j]);
        dfs(heights, visited, i-1, j, heights[i][j]);
        dfs(heights, visited, i, j+1, heights[i][j]);
        dfs(heights, visited, i, j-1, heights[i][j]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        // ตรวจสอบจากขอบมหาสมุทรแปซิฟิก (บนและซ้าย)
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0, INT_MIN);
        }
        for (int j = 0; j < cols; j++) {
            dfs(heights, pacific, 0, j, INT_MIN);
        }
        
        // ตรวจสอบจากขอบมหาสมุทรแอตแลนติก (ล่างและขวา)
        for (int i = 0; i < rows; i++) {
            dfs(heights, atlantic, i, cols-1, INT_MIN);
        }
        for (int j = 0; j < cols; j++) {
            dfs(heights, atlantic, rows-1, j, INT_MIN);
        }
        
        // หาจุดที่น้ำไหลไปทั้งสองมหาสมุทรได้
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};