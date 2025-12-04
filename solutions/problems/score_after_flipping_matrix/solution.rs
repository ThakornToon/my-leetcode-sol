impl Solution {
    pub fn matrix_score(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut grid = grid;
        
        // ขั้นตอน 1: ทำให้บิตแรกเป็น 1
        for i in 0..m {
            if grid[i][0] == 0 {
                for j in 0..n {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        // ขั้นตอน 2: ปรับคอลัมน์
        for j in 1..n {
            let mut count_one = 0;
            for i in 0..m {
                count_one += grid[i][j];
            }
            
            if count_one < (m as i32) - count_one {
                for i in 0..m {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        // ขั้นตอน 3: คำนวณคะแนน
        let mut score = 0;
        for i in 0..m {
            let mut row_value = 0;
            for j in 0..n {
                row_value = (row_value << 1) | grid[i][j];
            }
            score += row_value;
        }
        
        score
    }
}