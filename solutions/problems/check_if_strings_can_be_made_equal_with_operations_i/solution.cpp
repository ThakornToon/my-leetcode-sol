class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // ตรวจสอบกลุ่ม index คู่ (0 และ 2)
        bool evenMatch = (s1[0] == s2[0] && s1[2] == s2[2]) ||
                        (s1[0] == s2[2] && s1[2] == s2[0]);
        
        // ตรวจสอบกลุ่ม index คี่ (1 และ 3)
        bool oddMatch = (s1[1] == s2[1] && s1[3] == s2[3]) ||
                        (s1[1] == s2[3] && s1[3] == s2[1]);
        
        return evenMatch && oddMatch;
    }
};