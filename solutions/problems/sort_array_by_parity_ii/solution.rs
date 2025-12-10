impl Solution {
    pub fn sort_array_by_parity_ii(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut nums = nums;
        // Pass 1: จัดให้เลขคู่อยู่หน้าสุด (เหมือน Parity I)
        let mut i = 0;
        let mut j = n - 1;
        
        while i < j {
            if nums[i] % 2 == 0 {
                i += 1;
            } else if nums[j] % 2 == 1 {
                j -= 1;
            } else {
                nums.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        
        // Pass 2: สลับให้ถูกตำแหน่ง
        // ตอนนี้ครึ่งแรกเป็นเลขคู่ ครึ่งหลังเป็นเลขคี่
        let mut i = 1;          // เริ่มที่ตำแหน่งคี่แรก
        let mut j = n - 2;      // เริ่มที่ตำแหน่งคู่สุดท้าย
        
        while i < j {
            nums.swap(i, j);
            i += 2;
            j -= 2;
        }
        
        nums
    }
}