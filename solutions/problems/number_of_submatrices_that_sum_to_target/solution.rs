impl Solution {
    pub fn num_submatrix_sum_target(matrix: Vec<Vec<i32>>, target: i32) -> i32 {
        use std::collections::HashMap;
        let m = matrix.len();
        let n = matrix[0].len();
        let mut count = 0;

        // คำนวณ prefix sum สำหรับแต่ละแถว
        let mut prefix = vec![vec![0; n + 1]; m + 1];
        for i in 1..=m {
            for j in 1..=n {
                prefix[i][j] = matrix[i-1][j-1] + prefix[i][j-1];
            }
        }

        // สร้างสี่เหลี่ยมที่เป็นไปได้จาก  c1 ถึง c2 และคิดตั้งแต่ r
        for c1 in 1..=n {
            for c2 in c1..=n {
                let mut sum = 0;
                let mut map = HashMap::new();
                map.insert(0, 1);

                for r in 1..=m {
                    sum += prefix[r][c2] - prefix[r][c1-1]; // ผลรวมในสี่เหลี่ยม
                    count += *map.get(&(sum - target)).unwrap_or(&0); // หาจำนวนสี่เหลี่ยมที่มีผลรวม = target 
                    *map.entry(sum).or_insert(0) += 1;
                }
            }
        }

        count
    }
}