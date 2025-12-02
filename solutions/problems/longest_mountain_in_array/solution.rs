impl Solution {
    pub fn longest_mountain(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        if n < 3 {
            return 0;
        }
        
        let mut max_len = 0;
        let mut i = 1;
        
        while i < n - 1 {
            // ตรวจสอบว่าเป็นจุดสูงสุดหรือไม่
            if arr[i] > arr[i-1] && arr[i] > arr[i+1] {
                // ขยายไปทางซ้าย
                let mut left = i - 1;
                while left > 0 && arr[left] > arr[left-1] {
                    left -= 1;
                }
                
                // ขยายไปทางขวา
                let mut right = i + 1;
                while right < n - 1 && arr[right] > arr[right+1] {
                    right += 1;
                }
                
                // อัพเดทค่ามากสุด
                max_len = max_len.max(right - left + 1);
                
                // ข้ามไปยังจุดถัดไป
                i = right;
            } else {
                i += 1;
            }
        }
        
        max_len as i32
    }
}