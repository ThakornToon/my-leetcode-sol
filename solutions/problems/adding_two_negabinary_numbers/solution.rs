/*
base 2
sum = a + b + carry
digit = sum % 2
new_carry = sum / 2

base -2
sum = a + b + carry
digit = ((sum % 2) + 2) % 2 // 0 or 1
new_carry = (digit - sum) / 2} // sum = digit + new_carry * (-2)
*/
impl Solution {
    pub fn add_negabinary(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::new();
        let mut i = arr1.len() as i32 - 1;
        let mut j = arr2.len() as i32 - 1;
        let mut carry = 0;
        
        while i >= 0 || j >= 0 || carry != 0 {
            let mut sum = carry;
            
            if i >= 0 {
                sum += arr1[i as usize];
                i -= 1;
            }
            if j >= 0 {
                sum += arr2[j as usize];
                j -= 1;
            }
            
            // ใช้สูตร: digit = ((sum % 2) + 2) % 2
            // ใน Rust: rem_euclid หาเศษแบบยุคลิด (ได้ค่าบวกเสมอ)
            let digit = sum.rem_euclid(2);  // ได้ 0 หรือ 1 เสมอ
            let new_carry = (digit - sum) / 2;
            
            result.push(digit);
            carry = new_carry;
        }
        
        // กลับลำดับและลบ leading zeros
        result.reverse();
        
        // ลบเลข 0 นำหน้า (แต่ต้องเหลืออย่างน้อย 1 หลัก)
        while result.len() > 1 && result[0] == 0 {
            result.remove(0);
        }
        
        result
    }
}