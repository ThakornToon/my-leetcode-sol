impl Solution {
    pub fn largest_sum_after_k_negations(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        let mut k = k;
        
        // เรียงตาม absolute value จากมากไปน้อย
        nums.sort_by_key(|&x| -x.abs());
        
        // Negate negative numbers ก่อน
        for i in 0..nums.len() {
            if nums[i] < 0 && k > 0 {
                nums[i] = -nums[i];
                k -= 1;
            }
        }
        
        // หาก k เหลือและเป็นคี่, negate ค่าที่น้อยที่สุด
        if k % 2 == 1 {
            let len = nums.len();
            nums[len - 1] = -nums[len - 1]; // สุดท้ายคือค่าที่น้อยที่สุด
        }
        
        nums.iter().sum()
    }
}