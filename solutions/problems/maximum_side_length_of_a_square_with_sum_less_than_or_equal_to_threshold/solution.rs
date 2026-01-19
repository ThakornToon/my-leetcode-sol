impl Solution {
    pub fn max_side_length(mat: Vec<Vec<i32>>, threshold: i32) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        
        // สร้าง prefix sum
        let mut prefix = vec![vec![0; n + 1]; m + 1];
        
        for i in 1..=m {
            for j in 1..=n {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] 
                             + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        let mut max_side = 0;
        
        // เพิ่มขนาดทีละ 1
        for side in 1..=m.min(n) {
            let mut found = false;
            
            for i in 0..=m - side {
                for j in 0..=n - side {
                    let sum = prefix[i+side][j+side] - prefix[i][j+side] 
                            - prefix[i+side][j] + prefix[i][j];
                    
                    if sum <= threshold {
                        found = true;
                        max_side = side;
                        break;
                    }
                }
                if found { break; }
            }
            
            if !found {
                break;  // ไม่มีสี่เหลี่ยมขนาดนี้
            }
        }
        
        max_side as i32
    }
}