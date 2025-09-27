impl Solution {
    pub fn maximum_product(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        
        let mut max1 = i32::MIN;
        let mut max2 = i32::MIN;
        let mut max3 = i32::MIN;
        let mut min1 = i32::MAX;
        let mut min2 = i32::MAX;
        
        for &num in &nums {
            // อัปเดตสามค่ามากที่สุด
            if num > max1 {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if num > max2 {
                max3 = max2;
                max2 = num;
            } else if num > max3 {
                max3 = num;
            }
            
            // อัปเดตสองค่าน้อยที่สุด
            if num < min1 {
                min2 = min1;
                min1 = num;
            } else if num < min2 {
                min2 = num;
            }
        }
        
        let product1 = max1 * max2 * max3;
        let product2 = min1 * min2 * max1;
        
        if product1 > product2 { product1 } else { product2 }
    }
}