impl Solution {
    pub fn max_turbulence_size(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        if n <= 1 {
            return n as i32;
        }
        
        let mut up = 1;   // turbulent ที่ลงท้ายด้วยขึ้น
        let mut down = 1; // turbulent ที่ลงท้ายด้วยลง
        let mut max_len = 1;
        
        for i in 1..n {
            match arr[i].cmp(&arr[i - 1]) {
                std::cmp::Ordering::Greater => {
                    // ขึ้น: ต้องต่อจากลง
                    up = down + 1;
                    down = 1;
                }
                std::cmp::Ordering::Less => {
                    // ลง: ต้องต่อจากขึ้น
                    down = up + 1;
                    up = 1;
                }
                std::cmp::Ordering::Equal => {
                    // เท่ากัน: เริ่มใหม่
                    up = 1;
                    down = 1;
                }
            }
            
            max_len = max_len.max(up.max(down));
        }
        
        max_len
    }
}