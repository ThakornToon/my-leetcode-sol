impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.is_empty() {
            return 0;
        }
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut heights = vec![0; cols + 1];
        let mut maxArea = 0;
        
        for row in &matrix {
            for (i, &ch) in row.iter().enumerate() {
                if ch == '1' {
                    heights[i] += 1
                }
                else {
                    heights[i] = 0;
                }
            }
            
            for i in 0..cols {
                let mut minHeight = heights[i];
                for j in i..cols {
                    minHeight = minHeight.min(heights[j]);
                    let area = minHeight * (j - i + 1) as i32;
                    maxArea = maxArea.max(area);
                }
            }
        }
        
        return maxArea;
    }
}