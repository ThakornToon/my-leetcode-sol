impl Solution {
    pub fn partition_disjoint(nums: Vec<i32>) -> i32 {
        let n = nums.len();
    
        // สร้าง vector สำหรับเก็บค่าสูงสุดจากซ้าย
        let mut max_left = vec![0; n];
        max_left[0] = nums[0];
        for i in 1..n {
            max_left[i] = max_left[i-1].max(nums[i]);
        }
        
        // สร้าง vector สำหรับเก็บค่าต่ำสุดจากขวา
        let mut min_right = vec![0; n];
        min_right[n-1] = nums[n-1];
        for i in (0..n-1).rev() {
            min_right[i] = min_right[i+1].min(nums[i]);
        }
        
        // หา partition point
        for i in 0..n-1 {
            if max_left[i] <= min_right[i+1] {
                return (i + 1) as i32; // ความยาวของ left partition
            }
        }
        
        n as i32 // กรณีที่ partition ทั้ง array
    }
}