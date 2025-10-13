impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        if n == 0 {
            return 0;
        }
        
        // สร้าง suffix min array
        let mut suffix_min = vec![0; n];
        suffix_min[n-1] = arr[n-1];
        for i in (0..n-1).rev() {
            suffix_min[i] = arr[i].min(suffix_min[i+1]);
        }
        
        let mut chunks = 1;
        let mut prefix_max = arr[0];
        
        for i in 0..n-1 {
            prefix_max = prefix_max.max(arr[i]);
            
            // ตรวจสอบว่าแบ่ง chunk ได้ไหม
            if prefix_max <= suffix_min[i+1] {
                chunks += 1;
            }
        }
        
        chunks
    }
}