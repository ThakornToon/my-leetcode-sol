impl Solution {
    pub fn cal_points(operations: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();
        
        for op in operations {
            match op.as_str() { // ใช้ as_str() เพื่อแปลงเป็น &str สำหรับใช้ใน match
                "+" => {
                    // บวกสองคะแนนล่าสุด
                    let last = stack.pop().unwrap();
                    let second_last = *stack.last().unwrap();
                    stack.push(last);
                    stack.push(last + second_last);
                },
                "D" => {
                    // คูณสองคะแนนล่าสุด
                    let last = *stack.last().unwrap();
                    stack.push(last * 2);
                },
                "C" => {
                    // ลบคะแนนล่าสุด
                    stack.pop();
                },
                _ => {
                    // จำนวนเต็ม
                    let num: i32 = op.parse().unwrap();
                    stack.push(num);
                }
            }
        }
        
        stack.iter().sum()
    }
}