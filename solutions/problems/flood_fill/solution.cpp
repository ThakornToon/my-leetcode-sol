class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // ถ้าสีใหม่เท่ากับสีเดิม ไม่ต้องทำอะไร
        if (image[sr][sc] == color) {
            return image;
        }
        
        int originalColor = image[sr][sc];
        dfs(image, sr, sc, originalColor, color);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor) {
        // Check boundaries
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) {
            return;
        }
        
        // Check if pixel should be filled
        if (image[r][c] != originalColor) {
            return;
        }
        
        // Change color
        image[r][c] = newColor;
        
        // Recursively fill adjacent pixels (4-directional)
        dfs(image, r + 1, c, originalColor, newColor); // down
        dfs(image, r - 1, c, originalColor, newColor); // up
        dfs(image, r, c + 1, originalColor, newColor); // right
        dfs(image, r, c - 1, originalColor, newColor); // left
    }
};