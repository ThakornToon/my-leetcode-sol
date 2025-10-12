impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        
        // ตรวจสอบทุก cell ยกเว้นแถวสุดท้ายและคอลัมน์สุดท้าย
        for i in 0..m - 1 {
            for j in 0..n - 1 {
                if matrix[i][j] != matrix[i + 1][j + 1] {
                    return false;
                }
            }
        }
        true
    }
}