impl Solution {
    pub fn diagonal_sort(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let mut mat = mat;
        
        for k in 0..m + n - 1 {
            // หาจุดเริ่มต้นแนวทแยง
            let start_i = if k < n { 0 } else { k - n + 1 };
            let start_j = if k < n { n - 1 - k } else { 0 };
            
            let mut i = start_i;
            let mut j = start_j;
            let mut values = Vec::new();
            
            while i < m && j < n {
                values.push(mat[i][j]);
                i += 1;
                j += 1;
            }
            
            values.sort();
            
            i = start_i;
            j = start_j;
            let mut idx = 0;
            while i < m && j < n {
                mat[i][j] = values[idx];
                i += 1;
                j += 1;
                idx += 1;
            }
        }
        
        mat
    }
}