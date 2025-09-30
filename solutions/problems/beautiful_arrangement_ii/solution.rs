impl Solution {
    pub fn construct_array(n: i32, k: i32) -> Vec<i32> {
        let n = n as usize;
        let k = k as usize;
        let mut result = Vec::with_capacity(n);
        let (mut left, mut right) = (1, n as i32);
        
        // สร้าง k-1 ความต่างแรก
        for i in 0..k {
            if i % 2 == 0 {
                result.push(left);
                left += 1;
            } else {
                result.push(right);
                right -= 1;
            }
        }
        
        // เติมส่วนที่เหลือ
        if k % 2 == 1 {
            // k คี่ -> เติมจากซ้ายไปขวา
            while left <= right {
                result.push(left);
                left += 1;
            }
        } else {
            // k คู่ -> เติมจากขวาไปซ้าย
            while left <= right {
                result.push(right);
                right -= 1;
            }
        }
        
        result
    }
}