impl Solution {
    pub fn can_make_pali_queries(s: String, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let n = s.len();
        let s_bytes = s.as_bytes();
        
        // สร้าง prefix parity array ว่าความยาวนั้นมีตัวอักษรใดบ้างที่มีคี่ตัว
        let mut prefix = vec![0; n + 1];
        
        for i in 0..n {
            let bit = 1 << (s_bytes[i] - b'a');
            prefix[i + 1] = prefix[i] ^ bit; // XOR คู่->คี่->คู่ 
            /*
            0 XOR 0 = 0
            0 XOR 1 = 1
            1 XOR 0 = 1
            1 XOR 1 = 0 
            */
        }
        
        let mut result = Vec::new();
        
        for query in queries {
            let left = query[0] as usize;
            let right = query[1] as usize;
            let k = query[2];
            
            // หา parity ของ substring
            // คู่ ^ คี่ = 1, คี่ ^ คี่ = 0, คู่ ^ คู่ = 0
            let parity: i32 = prefix[right + 1] ^ prefix[left];
            
            // นับจำนวน bit ที่เป็น 1
            let odd_count = parity.count_ones() as i32;
            
            // จำนวนการเปลี่ยนที่ต้องการ
            let needed_changes = odd_count / 2;
            
            result.push(needed_changes <= k);
        }
        
        result
    }
}