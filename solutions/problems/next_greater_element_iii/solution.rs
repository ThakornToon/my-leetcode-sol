/*
หา pivot: หาตำแหน่งที่ตัวเลขเริ่มลดลงจากขวาไปซ้าย
หา successor: หาตัวเลขที่ใหญ่กว่าตัว pivot ที่อยู่ทางขวาสุด
สลับตำแหน่ง: สลับตัว pivot กับ successor
กลับลำดับส่วนที่เหลือ: กลับลำดับตัวเลขทางขวาของ pivot เพื่อให้ได้ค่าที่น้อยที่สุด
*/

impl Solution {
    pub fn next_greater_element(n: i32) -> i32 {
        let mut digits: Vec<char> = n.to_string().chars().collect();
        let len = digits.len();
        
        // Step 1: Find the pivot
        let mut pivot = len as i32 - 2;
        while pivot >= 0 && digits[pivot as usize] >= digits[(pivot + 1) as usize] {
            pivot -= 1;
        }
        
        if pivot == -1 {
            return -1; // No greater number possible
        }
        
        // Step 2: Find the successor
        let mut successor = len - 1;
        while digits[successor] <= digits[pivot as usize] {
            successor -= 1;
        }
        
        // Step 3: Swap the pivot and successor
        digits.swap(pivot as usize, successor);
        
        // Step 4: Reverse the suffix
        digits[(pivot as usize + 1)..].reverse();
        
        // Convert back to number and check for 32-bit overflow
        match digits.into_iter().collect::<String>().parse::<i32>() {
            Ok(num) => num,
            Err(_) => -1,
        }
    }
}