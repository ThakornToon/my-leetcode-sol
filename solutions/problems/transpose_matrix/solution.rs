impl Solution {
    pub fn transpose(matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = matrix.len();      // จำนวนแถว
        let n = matrix[0].len();   // จำนวนคอลัมน์
        
        // สร้าง matrix ผลลัพธ์ขนาด n × m
        let mut result = vec![vec![0; m]; n];
        
        // คำนวณ transpose
        for i in 0..m {
            for j in 0..n {
                result[j][i] = matrix[i][j];
            }
        }
        
        result
    }
}