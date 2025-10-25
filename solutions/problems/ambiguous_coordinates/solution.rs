impl Solution {
    pub fn ambiguous_coordinates(s: String) -> Vec<String> {
        let numbers = &s[1..s.len()-1];  // เอาเครื่องหมายวงเล็บออก
        let mut answer = Vec::new();
        
        // ลองแบ่งทุกตำแหน่ง
        for i in 1..numbers.len() {
            let (left, right) = numbers.split_at(i);
            
            let left_options = Self::create_numbers(left);
            let right_options = Self::create_numbers(right);
            
            // รวมทุกคู่ที่เป็นไปได้
            for l in &left_options {
                for r in &right_options {
                    answer.push(format!("({}, {})", l, r));
                }
            }
        }
        
        answer
    }
    
    fn create_numbers(s: &str) -> Vec<String> {
        let mut numbers = Vec::new();
        
        // กรณีไม่มีจุดทศนิยม
        if s == "0" || !s.starts_with('0') {
            numbers.push(s.to_string());
        }
        
        // กรณีมีจุดทศนิยม
        for i in 1..s.len() {
            let (before_dot, after_dot) = s.split_at(i);
            
            // ตรวจสอบส่วนก่อนจุด
            if before_dot.starts_with('0') && before_dot != "0" {
                continue;
            }
            
            // ตรวจสอบส่วนหลังจุด
            if after_dot.ends_with('0') {
                continue;
            }
            
            numbers.push(format!("{}.{}", before_dot, after_dot));
        }
        
        numbers
    }
}