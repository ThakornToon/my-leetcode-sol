impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut max_val = 0;
        let mut chunks = 0;
        
        for (i, &num) in arr.iter().enumerate() {
            if num > max_val {
                max_val = num;
            }
            
            // ถ้าค่าสูงสุดเท่ากับ index ปัจจุบัน แสดงว่าแบ่ง chunk ได้
            if max_val == i as i32 {
                chunks += 1;
            }
        }
        
        chunks
    }
}