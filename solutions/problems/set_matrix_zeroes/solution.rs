impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut col0_0 = false;
        let mut row0_0 = false;
        let matrixSize = matrix.len();
        let matrixColSize = matrix[0].len();
        for i in 1..matrixSize {
            if matrix[i][0] == 0 {
                col0_0 = true;
            }
        }
        for i in 1..matrixColSize {
            if matrix[0][i] == 0 {
                row0_0 = true;
            }
        }
        if matrix[0][0] == 0 {
            col0_0 = true;
            row0_0 = true;
        }

        for i in 1..matrixSize {
            for j in 1..matrixColSize {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }   
            }
        }

        let max = matrixSize.max(matrixColSize);
        for i in 1..max {
            if i < matrixColSize && matrix[0][i] == 0 {
                for j in 1..matrixSize {
                    matrix[j][i] = 0;
                }
            }
            if i < matrixSize && matrix[i][0] == 0 { 
                for j in 1..matrixColSize {
                    matrix[i][j] = 0;
                }
            }
        }
    
        if row0_0 {
            for i in 0..matrixColSize {
                matrix[0][i] = 0;
            }
        }
        if col0_0 {
            for i in 0..matrixSize {
                matrix[i][0] = 0;
            }
        }
    }
}