impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let total: i32 = arr.iter().sum();
        
        // ตรวจสอบว่าหารด้วย 3 ลงตัวไหม
        if total % 3 != 0 {
            return false;
        }
        
        let target = total / 3;
        let mut current_sum = 0;
        let mut count = 0;
        
        for &num in &arr {
            current_sum += num;
            
            if current_sum == target {
                count += 1;
                current_sum = 0;
            }
        }
        
        return count >= 3;
    }
}