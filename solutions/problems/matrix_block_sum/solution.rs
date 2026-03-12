impl Solution {
    pub fn matrix_block_sum(mat: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let k = k as usize;
        
        // สร้าง prefix sum array
        let mut prefix = vec![vec![0; n + 1]; m + 1];
        
        for i in 0..m {
            for j in 0..n {
                prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + 
                                       prefix[i + 1][j] - prefix[i][j];
            }
        }
        
        // สร้างผลลัพธ์
        let mut result = vec![vec![0; n]; m];
        
        for i in 0..m {
            for j in 0..n {
                let r1 = (i as i32 - k as i32).max(0) as usize;
                let c1 = (j as i32 - k as i32).max(0) as usize;
                let r2 = (i + k).min(m - 1);
                let c2 = (j + k).min(n - 1);
                
                result[i][j] = prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] - 
                              prefix[r2 + 1][c1] + prefix[r1][c1];
            }
        }
        
        result
    }
}