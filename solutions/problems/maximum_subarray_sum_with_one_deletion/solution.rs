impl Solution {
    pub fn maximum_sum(arr: Vec<i32>) -> i32 {
        let n = arr.len();        
        let mut dp0 = arr[0];  // ไม่เคยลบ
        let mut dp1 = 0;       // ลบไปแล้ว 1 ตัว
        let mut result = arr[0];
        
        for i in 1..n {
            // ถ้าเราอยู่ในสถานะ "ลบแล้ว 1 ตัว":
            // 1. ลบตัวปัจจุบัน: ใช้ dp0 ก่อนหน้า (ไม่ลบ) + 0
            // 2. ไม่ลบตัวปัจจุบัน: ใช้ dp1 ก่อนหน้า + arr[i]
            dp1 = dp0.max(dp1 + arr[i]);
            
            // สถานะ "ไม่เคยลบ": Kadane's algorithm ปกติ
            dp0 = arr[i].max(dp0 + arr[i]);
            
            // อัปเดตคำตอบ
            result = result.max(dp0.max(dp1));
        }
        
        result
    }
}