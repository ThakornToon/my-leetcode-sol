impl Solution {
    pub fn add_strings(num1: String, num2: String) -> String {
        let l1 = num1.len();
        let l2 = num2.len();
        let num1: Vec<u8> = num1.bytes().rev().collect();
        let num2: Vec<u8> = num2.bytes().rev().collect();
        let mut result: String = String::new();
        let mut carry: i32 = 0;
        let mut it: usize = 0;
        while it < l1 || it < l2 || carry == 1 {
            let mut sum: i32 = carry;
            if (it < l1) {
                sum += (num1[it] - b'0') as i32;
            }
            if (it < l2) {
                sum += (num2[it] - b'0') as i32;
            }
            result.push(((sum % 10) as u8 + b'0') as char);
            carry = sum / 10;
            it += 1;
        }
        return result.chars().rev().collect();
    }
}