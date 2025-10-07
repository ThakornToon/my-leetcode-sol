impl Solution {
    pub fn flood_fill(mut image: Vec<Vec<i32>>, sr: i32, sc: i32, new_color: i32) -> Vec<Vec<i32>> {
        // ถ้าสีใหม่เท่ากับสีเดิม ไม่ต้องทำอะไร
        let sr = sr as usize;
        let sc = sc as usize;
        if image[sr][sc] == new_color {
            return image;
        }
        
        let original_color = image[sr][sc];
        Self::dfs(&mut image, sr, sc, original_color, new_color);
        image
    }
    
    fn dfs(image: &mut Vec<Vec<i32>>, r: usize, c: usize, original_color: i32, new_color: i32) {
        // Check boundaries
        if r < 0 || r >= image.len() || c < 0 || c >= image[0].len() {
            return;
        }
                
        // Check if pixel should be filled
        if image[r][c] != original_color {
            return;
        }
        
        // Change color
        image[r][c] = new_color;
        
        // Recursively fill adjacent pixels
        Self::dfs(image, r + 1, c, original_color, new_color); // down
        Self::dfs(image, r - 1, c, original_color, new_color); // up
        Self::dfs(image, r, c + 1, original_color, new_color); // right
        Self::dfs(image, r, c - 1, original_color, new_color); // left
    }
}