impl Solution {
    pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let m = matrix.len();
        let n = matrix[0].len();
        
        // หาค่าสูงสุดในแต่ละคอลัมน์
        let col_maxs: Vec<i32> = (0..n)
            .map(|j| (0..m).map(|i| matrix[i][j]).max().unwrap())
            .collect();
        
        let mut result = Vec::new();
        
        for i in 0..m {
            let mut row_min = matrix[i][0];
            let mut index = 0;
            
            // หาตำแหน่งของค่าต่ำสุด
            for j in 0..n {
                if matrix[i][j] < row_min {
                    row_min = matrix[i][j];
                    index = j;
                }
            }

            if row_min == col_maxs[index] {
                result.push(row_min);
            }
        }
        
        result
    }
}