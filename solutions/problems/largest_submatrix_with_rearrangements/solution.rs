impl Solution {
    pub fn largest_submatrix(matrix: Vec<Vec<i32>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut matrix = matrix;
        let mut max_area = 0;
        
        for i in 0..m {
            // อัปเดตความสูงจากแถวก่อนหน้า
            for j in 0..n {
                if i > 0 && matrix[i][j] == 1 {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
            
            // เรียงลำดับความสูงในแถวนี้
            let mut heights = matrix[i].clone();
            heights.sort_unstable_by(|a, b| b.cmp(a));
            
            // คำนวณพื้นที่
            for j in 0..n {
                if heights[j] == 0 { break; }
                max_area = max_area.max(heights[j] * (j as i32 + 1));
            }
        }
        
        max_area
    }
}