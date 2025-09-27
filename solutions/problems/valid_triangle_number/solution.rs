impl Solution {
    pub fn triangle_number(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n < 3 {
            return 0;
        }
        let mut nums = nums;
        nums.sort();
        let mut count = 0;
        
        // Fix ด้านที่ใหญ่ที่สุด
        for c in (2..n).rev() {
            let mut a = 0;
            let mut b = c - 1;
            
            while a < b {
                if nums[a] + nums[b] > nums[c] {
                    // ทุกค่าระหว่าง a ถึง b-1 ใช้ได้กับ b นี้
                    count += (b - a) as i32;
                    b -= 1;
                } else {
                    a += 1;
                }
            }
        }
        
        count
    }
}