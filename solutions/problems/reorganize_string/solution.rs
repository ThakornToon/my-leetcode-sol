impl Solution {
    pub fn reorganize_string(s: String) -> String {
        let mut count = [0; 26];
        let n = s.len();
        
        // นับความถี่
        for c in s.chars() {
            count[(c as usize) - ('a' as usize)] += 1;
        }
        
        // หาตัวอักษรที่มีความถี่สูงสุด
        let mut max_count = 0;
        let mut max_index = 0;
        for i in 0..26 {
            if count[i] > max_count {
                max_count = count[i];
                max_index = i;
            }
        }
        
        // ตรวจสอบความเป็นไปได้
        if max_count > (n + 1) / 2 {
            return String::new();
        }
        
        let mut result = vec![' '; n];
        let mut index = 0;
        
        // ใส่ตัวอักษรที่มีความถี่สูงสุดก่อนในตำแหน่งคู่
        while count[max_index] > 0 {
            result[index] = (max_index as u8 + b'a') as char;
            index += 2;
            count[max_index] -= 1;
        }
        
        // ใส่ตัวอักษรที่เหลือ
        for i in 0..26 {
            while count[i] > 0 {
                if index >= n {
                    index = 1;
                }
                result[index] = (i as u8 + b'a') as char;
                index += 2;
                count[i] -= 1;
            }
        }
        
        result.into_iter().collect()
    }
}