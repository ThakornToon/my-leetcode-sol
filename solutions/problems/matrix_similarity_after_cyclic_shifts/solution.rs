impl Solution {
    pub fn are_similar(mat: Vec<Vec<i32>>, k: i32) -> bool {
        let m = mat.len();
        let n = mat[0].len();
        let k = (k as usize) % n;
        
        if k == 0 {
            return true;
        }
        
        mat.iter().enumerate().all(|(i, row)| {
            if i % 2 == 0 {
                // shift ซ้าย: ตรวจสอบว่า row[j] == row[(j+k)%n]
                row.iter().enumerate().all(|(j, &val)| {
                    val == row[(j + k) % n]
                })
            } else {
                // shift ขวา: ตรวจสอบว่า row[j] == row[(j+n-k)%n]
                row.iter().enumerate().all(|(j, &val)| {
                    val == row[(j + n - k) % n]
                })
            }
        })
    }
}