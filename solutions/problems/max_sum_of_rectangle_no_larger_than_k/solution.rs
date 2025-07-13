impl Solution {
    pub fn max_sum_submatrix(matrix: Vec<Vec<i32>>, k: i32) -> i32 {
        use std::collections::BTreeSet;
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut res = i32::MIN;
        
        // ตรวจสอบว่าจำเป็นต้อง transpose เพื่อลดเวลาคิดไหม
        let transpose = rows > cols;
        let (rows, cols) = if transpose {
            (cols, rows)
        } else {
            (rows, cols)
        };
        
        // จับคู่ขอบเขตที่เป็นไปได้ r1 จนถึง r2
        for r1 in 0..rows {
            let mut col_sums = vec![0; cols]; // ผลรวมในแต่ละ col สะสม
            for r2 in r1..rows {
                for c in 0..cols { 
                    col_sums[c] += if transpose {
                        matrix[c][r2]
                    } else {
                        matrix[r2][c]
                    };
                }
                
                // ใช้ Kadane's algorithm แบบปรับปรุง
                let mut prefix_sums = BTreeSet::new(); // set เรียงกัน
                prefix_sums.insert(0);
                let mut curr_sum = 0;
                
                for &num in &col_sums { 
                    curr_sum += num; // สร้างสี่เหลี่ยมจากผลบวก col
                    if let Some(&x) = prefix_sums.range((curr_sum - k)..).next() { // เมธอด range ของ BTreeSet จะคืนค่า iterator ที่ชี้ไปยังค่าแรกที่มากกว่าหรือเท่ากับ curr_sum - k, .next()ดึงค่าแรกจาก iterator ที่ได้จาก range
                        res = res.max(curr_sum - x); // ลบกับผลรวม col ก่อนหน้านี้ในแถวเดียวกัน
                        if res == k {
                            return k;
                        }
                    }
                    prefix_sums.insert(curr_sum); // เก็บสี่เหลี่ยม
                }
            }
        }
        
        res
    }
}