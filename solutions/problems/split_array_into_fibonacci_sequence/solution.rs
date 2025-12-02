impl Solution {
    pub fn split_into_fibonacci(num: String) -> Vec<i32> {
        let mut result = Vec::new();
        let bytes: &[u8] = num.as_bytes();
        
        if Self::backtrack(bytes, 0, &mut result) {
            return result;
        }
        
        vec![]
    }

    fn backtrack(bytes: &[u8], start: usize, result: &mut Vec<i32>) -> bool {
        if start == bytes.len() {
            return result.len() >= 3;
        }
        
        let mut current: i64 = 0;
        
        for i in start..bytes.len() {
            // ตรวจสอบ leading zero
            if bytes[start] == b'0' && i > start {
                break;
            }
            
            // สร้างตัวเลขจาก digit
            current = current * 10 + (bytes[i] - b'0') as i64;
            
            // ตรวจสอบ overflow
            if current > i32::MAX as i64 {
                break;
            }
            
            let n = result.len();
            
            // ตรวจสอบสมการฟีโบนัชชี
            if n >= 2 {
                let sum = result[n-1] as i64 + result[n-2] as i64;
                if current < sum {
                    continue;
                } else if current > sum {
                    break;
                }
            }
            
            // current == sum เพิ่มเข้า result
            result.push(current as i32);
            
            // Backtrack 
            if Self::backtrack(bytes, i + 1, result) {
                return true;
            }
            result.pop();
        }
        
        false
    }
}