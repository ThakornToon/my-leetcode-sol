impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let mut row = matrix.len() - 1;  // เริ่มจากมุมซ้ายล่าง
        let mut col = 0;
        
        loop {
            if matrix[row][col] == target {
                return true;
            } else if matrix[row][col] > target {
                if row == 0 {
                    return false;
                }
                row -= 1;  // ไปทางบน (ค่าลดลง)
            } else {
                col += 1;  // ไปทางขวา (ค่าเพิ่มขึ้น)
                if col == matrix[0].len() {
                    return false;
                }
            }
        }
        return false;
    }
}