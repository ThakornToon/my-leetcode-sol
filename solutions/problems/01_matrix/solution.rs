impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let max_value = (m + n) as i32;
        let mut dist = mat.clone();
        
        // Forward pass: top-left to bottom-right
        for r in 0..m {
            for c in 0..n {
                if dist[r][c] == 0 {
                    continue;
                }
                
                let top = if r > 0 { dist[r-1][c] } else { max_value };
                let left = if c > 0 { dist[r][c-1] } else { max_value };
                dist[r][c] = top.min(left) + 1;
            }
        }
        
        // Backward pass: bottom-right to top-left
        for r in (0..m).rev() {
            for c in (0..n).rev() {
                if dist[r][c] == 0 {
                    continue;
                }
                
                let bottom = if r + 1 < m { dist[r+1][c] } else { max_value };
                let right = if c + 1 < n { dist[r][c+1] } else { max_value };
                let new_dist = bottom.min(right) + 1;
                dist[r][c] = dist[r][c].min(new_dist);
            }
        }
        
        dist
    }
}