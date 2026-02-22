/*
4x + 2y = T
x + y = C

x = (T - 2C) / 2
y = C - x

x ต้องเป็นจำนวนเต็ม ≥ 0
y ต้องเป็นจำนวนเต็ม ≥ 0
*/

impl Solution {
    pub fn num_of_burgers(tomato_slices: i32, cheese_slices: i32) -> Vec<i32> {
        // ตรวจสอบเงื่อนไขเบื้องต้น
        if tomato_slices % 2 != 0 {
            return vec![];
        }
        
        let diff = tomato_slices - 2 * cheese_slices;
        
        // ตรวจสอบว่า diff เป็นเลขคู่และ >= 0
        if diff < 0 || diff % 2 != 0 {
            return vec![];
        }
        
        let jumbo = diff / 2;
        let small = cheese_slices - jumbo;
        
        // ตรวจสอบว่า small >= 0
        if small < 0 {
            return vec![];
        }
        
        // ตรวจสอบอีกครั้ง (ป้องกัน overflow)
        if 4 * jumbo + 2 * small != tomato_slices {
            return vec![];
        }
        
        vec![jumbo, small]
    }
}