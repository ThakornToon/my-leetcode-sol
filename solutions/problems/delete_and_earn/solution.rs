impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let maxNum = *nums.iter().max().unwrap() as usize;
        let mut points = vec![0; maxNum + 1];
        
        // สร้าง points array แทนบ้านแต่ละหลัง / เมื่อลลบเลขนั้นๆ
        for &num in &nums {
            points[num as usize] += num;
        }
        
        // เหมือน House Robber
        let mut prev2 = 0; // ลบหมายเลข 0
        let mut currentMax = points[1]; // ลบหมายเลข 1
        for i in 2..=maxNum{
            let current = currentMax.max(prev2 + points[i]); // ค่ามากสุดโดยเลือกว่าจะลบหรือไม่ลบอันปัจจุบัน
            prev2 = currentMax; // ไม่ลบอันปัจจุบัน
            currentMax = current; // ค่ามากสุดโดยเลือกว่าจะลบหรือไม่ลบอันปัจจุบัน
        }
        
        return currentMax;
    }
}