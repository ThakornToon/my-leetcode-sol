impl Solution {
    pub fn add_to_array_form(num: Vec<i32>, k: i32) -> Vec<i32> {
        let mut k = k;
        let mut res = Vec::new();
        
        // วนจากท้ายไปหน้า
        for &digit in num.iter().rev() {
            k += digit;
            res.push(k % 10);
            k /= 10;
        }
        
        // เพิ่มส่วนที่เหลือของ k
        while k > 0 {
            res.push(k % 10);
            k /= 10;
        }
        
        // กลับด้าน
        res.reverse();
        res
    }
}