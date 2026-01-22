impl Solution {
    pub fn minimum_pair_removal(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        
        // ตรวจสอบว่า non-decreasing อยู่แล้วหรือไม่
        if nums.windows(2).all(|w| w[0] <= w[1]) {
            return 0;
        }
        
        // สร้าง mutable copy
        let mut arr = nums.clone();
        let mut operations = 0;
        
        loop {
            // หาคู่ที่มีผลรวมน้อยที่สุด (ซ้ายสุดถ้าเท่ากัน)
            let mut min_sum = i32::MAX;
            let mut min_index = 0;
            
            for i in 0..arr.len() - 1 {
                let sum = arr[i] + arr[i + 1];
                if sum < min_sum {
                    min_sum = sum;
                    min_index = i;
                }
            }
            
            // ดำเนินการ merge
            arr[min_index] = min_sum;
            arr.remove(min_index + 1);
            operations += 1;
            
            // ตรวจสอบว่าเป็น non-decreasing แล้วหรือยัง
            if arr.windows(2).all(|w| w[0] <= w[1]) {
                break;
            }
            
            // ป้องกัน infinite loop (กรณีที่ arr เหลือ 1 ตัว)
            if arr.len() <= 1 {
                break;
            }
        }
        
        operations
    }
}