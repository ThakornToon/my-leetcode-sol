/*
90°: new[i][j] = mat[n-1-j][i]
180°: new[i][j] = mat[n-1-i][n-1-j]
270°: new[i][j] = mat[j][n-1-i]
*/

impl Solution {
    pub fn find_rotation(mat: Vec<Vec<i32>>, target: Vec<Vec<i32>>) -> bool {
        let n = mat.len();
        let mut mat = mat;
        
        for _ in 0..4 {
            if mat == target {
                return true;
            }
            Self::rotate(&mut mat);
        }
        
        false
    }

    // ฟังก์ชันหมุน 90 องศา
    fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        
        // transpose
        for i in 0..n {
            for j in i..n {
                let temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // reverse each row
        for row in matrix.iter_mut() {
            row.reverse();
        }
    }
}
