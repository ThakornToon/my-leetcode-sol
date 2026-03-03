impl Solution {
    pub fn smallest_divisor(nums: Vec<i32>, threshold: i32) -> i32 {
        let mut left = 1;
        let mut right = *nums.iter().max().unwrap();
        let mut result = right;
        
        while left <= right {
            let mid = left + (right - left) / 2;
            
            // คำนวณผลรวมของการหารด้วย mid
            let sum: i64 = nums.iter()
                .map(|&num| ((num as i64 + mid as i64 - 1) / mid as i64))
                .sum();
            
            if sum <= threshold as i64 {
                // ถ้าผลรวม <= threshold ลอง divisor ที่น้อยลง
                result = mid;
                right = mid - 1;
            } else {
                // ถ้าผลรวม > threshold ต้องใช้ divisor ที่มากขึ้น
                left = mid + 1;
            }
        }
        
        result
    }
}