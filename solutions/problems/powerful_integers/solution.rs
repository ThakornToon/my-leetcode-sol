use std::collections::HashSet;
impl Solution {
    pub fn powerful_integers(x: i32, y: i32, bound: i32) -> Vec<i32> {
        if bound < 2 {
            return Vec::new();
        }
        
        let mut result_set = HashSet::new();
        
        // สร้างลิสต์ของ x^i
        let mut x_powers = Vec::new();
        if x == 1 {
            x_powers.push(1);
        } else {
            let mut val = 1;
            while val <= bound {
                x_powers.push(val);
                // ตรวจสอบ overflow
                if let Some(next) = val.checked_mul(x as i32) {
                    val = next;
                } else {
                    break;
                }
            }
        }
        
        // สร้างลิสต์ของ y^j
        let mut y_powers = Vec::new();
        if y == 1 {
            y_powers.push(1);
        } else {
            let mut val = 1;
            while val <= bound {
                y_powers.push(val);
                if let Some(next) = val.checked_mul(y as i32) {
                    val = next;
                } else {
                    break;
                }
            }
        }
        
        // ทดสอบทุกคู่
        for &a in &x_powers {
            for &b in &y_powers {
                let sum = a + b;
                if sum <= bound {
                    result_set.insert(sum);
                } else {
                    // ถ้า b ใหญ่เกิน bound - a แล้ว break
                    break;
                }
            }
        }
        
        // แปลงเป็น vector และเรียงลำดับ
        let mut result: Vec<i32> = result_set.into_iter().collect();
        result.sort_unstable();
        result
    }
}