impl Solution {
    pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
        let (m, n) = (m as usize, n as usize);
        
        if original.len() != m * n {
            return Vec::new();
        }
        
        let mut result = vec![vec![0; n]; m];
        
        for i in 0..m {
            for j in 0..n {
                result[i][j] = original[i * n + j];
            }
        }
        
        result
    }
}