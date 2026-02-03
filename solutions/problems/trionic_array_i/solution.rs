impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut i = 0;
    
        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i+=1;
        }
        
        // ต้องมี increasing part (i > 0)
        if (i == 0 || i == n - 1) {
            return false;
        }
        
        // i ตอนนี้คือ peak (ตำแหน่งสูงสุด)
        // Phase 2: strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i+=1;
        }

        // ต้องมี decreasing part (i > 0)
        if (i == 0 || i == n - 1) {
            return false;
        }

        // Phase 3: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i+=1;
        }
        
        // ต้องเดินถึงตัวสุดท้าย
        return (i == n - 1);
    }
}