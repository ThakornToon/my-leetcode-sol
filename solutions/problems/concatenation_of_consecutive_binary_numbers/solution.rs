impl Solution {
    pub fn concatenated_binary(n: i32) -> i32 {
        let mut result = 0i64;  
        let mut length = 0i64; // ความยาว binary ของตัวเลขปัจจุบัน
        
        for i in 1..=(n as i64) {
            // ถ้า i เป็นเลขยกกำลังสอง ความยาว binary จะเพิ่มขึ้น 1
            // เช่น 1 (1), 2 (10), 4 (100), 8 (1000)
            if (i & (i - 1)) == 0 {
                length += 1;
            }
            
            result = ((result << length) | i) % 1000000007;
        }
        
        return result as i32;
    }
}