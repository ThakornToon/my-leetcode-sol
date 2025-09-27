impl Solution {
    pub fn find_unsorted_subarray(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n <= 1 {
            return 0;
        }
        
        let mut max_val = i32::MIN;
        let mut min_val = i32::MAX;
        let mut found_unsorted = false;
        
        // ตรวจสอบว่ามีส่วนที่ไมเรียงหรือไม่
        for i in 1..n {
            if nums[i] < nums[i-1] {
                found_unsorted = true;
                break;
            }
        }
        
        // ถ้าไม่มีส่วนที่ไมเรียงเลย
        if !found_unsorted {
            return 0;
        }
        
        // หาค่า min ในส่วนที่ยังไม่เรียง
        let mut flag = false;
        for i in 1..n {
            if nums[i] < nums[i-1] {
                flag = true;
            }
            if flag {
                min_val = min_val.min(nums[i]);
            }
        }
        
        // หาค่า max ในส่วนที่ยังไม่เรียง
        flag = false;
        for i in (0..n-1).rev() {
            if nums[i] > nums[i+1] {
                flag = true;
            }
            if flag {
                max_val = max_val.max(nums[i]);
            }
        }
        
        // หาตำแหน่งเริ่มต้น
        let mut left = 0;
        for i in 0..n {
            if min_val < nums[i] {
                left = i;
                break;
            }
        }
        
        // หาตำแหน่งสิ้นสุด
        let mut right = n - 1;
        for i in (0..n).rev() {
            if max_val > nums[i] {
                right = i;
                break;
            }
        }
        
        if right < left { 0 } else { (right - left + 1) as i32 }
    }
}