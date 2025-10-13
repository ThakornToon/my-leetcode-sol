class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        int i = 0, j = 0;
        
        while (i < n || j < n) {
            // ข้าม 'X' ใน start
            while (i < n && start[i] == 'X') i++;
            // ข้าม 'X' ใน end
            while (j < n && result[j] == 'X') j++;
            
            // จบทั้งคู่
            if (i == n && j == n) return true;
            // ความยาวไม่เท่ากันหลังจากข้าม X
            if (i == n || j == n) return false;
            
            // ตรวจสอบอักขระไม่ตรงกัน
            if (start[i] != result[j]) return false;
            
            // ตรวจสอบเงื่อนไขตำแหน่ง
            if (start[i] == 'L' && i < j) return false;  // L เคลื่อนที่ซ้ายได้เท่านั้น
            if (start[i] == 'R' && i > j) return false;  // R เคลื่อนที่ขวาได้เท่านั้น
            
            i++;
            j++;
        }
        
        return true;
    }
};