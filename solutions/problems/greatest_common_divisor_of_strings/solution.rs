impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        // ตรวจสอบเงื่อนไขพื้นฐาน: str1 + str2 ต้องเท่ากับ str2 + str1
        if format!("{}{}", str1, str2) != format!("{}{}", str2, str1) {
            return String::new();
        }
        
        // หา GCD ของความยาวทั้งสอง
        let len1 = str1.len();
        let len2 = str2.len();
        let gcd_len = Self::gcd(len1, len2);
        
        // เอา prefix ยาว gcd_len จาก str1
        str1[..gcd_len].to_string()
    }

    fn gcd(mut a: usize, mut b: usize) -> usize {
        // Euclidean algorithm
        while b != 0 {
            let temp = a % b;
            a = b;
            b = temp;
        }
        a
    }
}