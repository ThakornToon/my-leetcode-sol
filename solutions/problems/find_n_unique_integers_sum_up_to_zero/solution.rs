impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut result = Vec::new();
        let mut start = -n / 2;
        
        for _ in 0..n {
            result.push(start);
            start += 1;
            
            // ถ้า n เป็นคู่ ให้ข้าม 0
            if n % 2 == 0 && *result.last().unwrap() == 0 {
                *result.last_mut().unwrap() = start;
                start += 1;
            }
        }
        
        result

    }
}