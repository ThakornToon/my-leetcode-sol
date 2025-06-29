impl Solution {
    fn dfs(heights: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>, i: i32, j: i32, prev_height: i32) {
        if i < 0 || i >= heights.len() as i32 || j < 0 || j >= heights[0].len() as i32 
            || visited[i as usize][j as usize] || heights[i as usize][j as usize] < prev_height {
            return;
        }
        
        visited[i as usize][j as usize] = true;
        
        // ตรวจสอบ 4 ทิศทาง
        Self::dfs(heights, visited, i + 1, j, heights[i as usize][j as usize]);
        Self::dfs(heights, visited, i - 1, j, heights[i as usize][j as usize]);
        Self::dfs(heights, visited, i, j + 1, heights[i as usize][j as usize]);
        Self::dfs(heights, visited, i, j - 1, heights[i as usize][j as usize]);
    }

    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if heights.is_empty() {
            return Vec::new();
        }
        
        let rows = heights.len();
        let cols = heights[0].len();
        
        let mut pacific = vec![vec![false; cols]; rows];
        let mut atlantic = vec![vec![false; cols]; rows];
        
        // ตรวจสอบจากขอบแปซิฟิก
        // ตรวจสอบจากขอบแอตแลนติก
        for i in 0..(rows as i32) {
            Self::dfs(&heights, &mut pacific, i, 0, i32::MIN);
            Self::dfs(&heights, &mut atlantic, i, (cols - 1) as i32, i32::MIN);
        }
        for j in 0..(cols as i32) {
            Self::dfs(&heights, &mut pacific, 0, j, i32::MIN);
            Self::dfs(&heights, &mut atlantic, (rows - 1) as i32, j, i32::MIN);
        }
        
        // หาจุดที่น้ำไหลไปทั้งสองมหาสมุทรได้
        let mut result = Vec::new();
        for i in 0..rows {
            for j in 0..cols {
                if pacific[i][j] && atlantic[i][j] {
                    result.push(vec![i as i32, j as i32]);
                }
            }
        }
        
        result
    }
}