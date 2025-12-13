impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        let n = arr.len();
        if n < 3 {
            return false;
        }
        
        let mut left = 0;
        let mut right = n - 1;
        
        // เดินจากซ้าย
        while left + 1 < n && arr[left] < arr[left + 1] {
            left += 1;
        }
        
        // เดินจากขวา
        while right > 0 && arr[right] < arr[right - 1] {
            right -= 1;
        }
        
        // ตรวจสอบว่าเป็นยอดเขาเดียวกันและไม่อยู่ที่ขอบ
        left > 0 && right < n - 1 && left == right
    }
}