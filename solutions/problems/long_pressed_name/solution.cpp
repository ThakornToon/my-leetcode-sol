class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int n = name.length(), m = typed.length();
        
        while (j < m) {
            if (i < n && name[i] == typed[j]) {
                // ตัวอักษรตรงกัน
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                // long pressed (ตัวอักษรซ้ำ)
                j++;
            } else {
                // ไม่ตรงและไม่ใช่ long pressed
                return false;
            }
        }
        
        // ตรวจสอบว่าใช้ตัวอักษรใน name หมดแล้ว
        return i == n;
    }
};