impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        
        const MIN_HALF: i32 = i32::MIN / 2;
        
        // dp[i][j] = dot product ที่ดีที่สุดเมื่อพิจารณา nums1 ยาว i และ nums2 ยาว j
        // ใช้แค่ 2 rows เพื่อลด memory usage
        let mut prev = vec![MIN_HALF; n + 1];
        let mut curr = vec![MIN_HALF; n + 1];
        
        for i in 1..=m {
            for j in 1..=n {
                let product = nums1[i - 1] * nums2[j - 1];
                
                curr[j] = prev[j - 1].saturating_add(product)
                    .max(product)
                    .max(prev[j])
                    .max(curr[j - 1]);
            }
            
            // สลับ rows สำหรับ iteration ถัดไป
            std::mem::swap(&mut prev, &mut curr);
            curr.fill(MIN_HALF);
        }
        
        prev[n]
    }
}