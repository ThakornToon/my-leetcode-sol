class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int count1 = 0; // นับจำนวนครั้งที่ใช้ s1
        int count2 = 0; // นับจำนวนครั้งที่สร้าง s2 ได้
        int i = 0; // index สำหรับ s1
        int j = 0; // index สำหรับ s2
        
        while (count1 < n1) {
            // ตรวจสอบตัวอักษรปัจจุบัน
            if (s1[i] == s2[j]) {
                j++; // ขยับไปตัวอักษรถัดไปใน s2
                
                // ถ้าสร้าง s2 ได้ครบ 1 ครั้ง
                if (j == s2.size()) {
                    j = 0; // รีเซ็ต index ของ s2
                    count2++; // นับจำนวนครั้งที่สร้าง s2 ได้
                }
            }
            
            i++; // ขยับไปตัวอักษรถัดไปใน s1
            
            // ถ้าใช้ s1 ครบ 1 ครั้ง
            if (i == s1.size()) {
                i = 0; // รีเซ็ต index ของ s1
                count1++; // นับจำนวนครั้งที่ใช้ s1
            }
        }
        
        // คืนค่าจำนวนครั้งที่สร้าง s2 ที่ทำซ้ำได้
        return count2 / n2;
    }
};