int uniqueLetterString(char* s) {
    int n = strlen(s);
    int last[26], prev[26]; // เก็บตำแหน่งของตัวอักษร
    
    // เริ่มต้นตำแหน่ง
    for (int i = 0; i < 26; i++) {
        last[i] = -1;
        prev[i] = -1;
    }
    
    int total = 0; // ผลรวม contribution ทั้งหมด ณ ตำแหน่งปัจจุบัน
    int result = 0; // คำตอบสุดท้าย
    int contribution[26] = {0}; // จำนวน substring ที่ตัวอักษร c เป็น unique ณ ตำแหน่งปัจจุบัน
    
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'A';
        
        // ลบ contribution เดิม
        total -= contribution[c];
        
        // คำนวณ contribution ใหม่
        contribution[c] = i - last[c];
        total += contribution[c];
        
        // อัพเดตตำแหน่ง
        prev[c] = last[c];
        last[c] = i;
        
        result += total;
    }
    
    return result;
}