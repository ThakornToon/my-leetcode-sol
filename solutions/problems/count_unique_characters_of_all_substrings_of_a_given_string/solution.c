int uniqueLetterString(char* s) {
    int n = strlen(s);
    int last[26]; // เก็บตำแหน่งของตัวอักษร
    
    // เริ่มต้นตำแหน่ง
    for (int i = 0; i < 26; i++) {
        last[i] = -1;
    }
    
    int total = 0; // ผลรวม contribution ทั้งหมด ณ ตำแหน่งปัจจุบัน
    int result = 0; // คำตอบสุดท้าย
    int contribution[26] = {0}; // จำนวน substring ที่ตัวอักษร c เป็น unique ณ ตำแหน่งปัจจุบัน
    /*
    ABCABA
    A, con[A]=1, total=1, res=1
    AB, B con[B]=2, total=3, res=4
    ABC, BC, C con[C]=3, total=6, res=10
    ABCA, BCA, CA, A total=5, con[A]=3, total=8, res=18
    ABCAB, BCAB, CAB, AB, B total=6, con[B]=3, total=9, res=27
    ABCABA, BCABA, CABA, ABA, BA, A total=6, con[A]=2, total=8, res=35
    */
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'A';
        
        // ลบ contribution เดิม
        total -= contribution[c];
        
        // คำนวณ contribution ใหม่
        contribution[c] = i - last[c];
        total += contribution[c];
        
        // อัพเดตตำแหน่ง
        last[c] = i;
        
        result += total;
    }
    
    return result;
}