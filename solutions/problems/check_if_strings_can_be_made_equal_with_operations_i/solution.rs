impl Solution {
    pub fn can_be_equal(s1: String, s2: String) -> bool {
        let s1 = s1.as_bytes();
        let s2 = s2.as_bytes();

        // ตรวจสอบกลุ่ม index คู่ (0 และ 2)
        let evenMatch = (s1[0] == s2[0] && s1[2] == s2[2]) ||
                        (s1[0] == s2[2] && s1[2] == s2[0]);
        
        // ตรวจสอบกลุ่ม index คี่ (1 และ 3)
        let oddMatch = (s1[1] == s2[1] && s1[3] == s2[3]) ||
                        (s1[1] == s2[3] && s1[3] == s2[1]);
        
        return evenMatch && oddMatch;
    }
}