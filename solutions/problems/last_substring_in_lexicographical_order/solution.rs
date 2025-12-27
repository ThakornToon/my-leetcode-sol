impl Solution {
    pub fn last_substring(s: String) -> String {
        let bytes = s.as_bytes();
        
        // สร้าง iterator สำหรับทุก suffix
        let suffixes = (0..bytes.len()).map(|i| &s[i..]);
        
        // หา suffix ที่ใหญ่ที่สุด
        suffixes.max().unwrap_or("").to_string()
    }
}