impl Solution {
    pub fn matrix_reshape(mat: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let (r, c) = (r as usize, c as usize);
        
        if (m * n) != (r * c) {
            return mat;
        }
        
        let mut result = vec![vec![0; c]; r];
        
        for i in 0..m * n {
            result[i / c][i % c] = mat[i / n][i % n];
        }
        
        result
    }
}