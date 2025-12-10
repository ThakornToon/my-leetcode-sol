int minAddToMakeValid(char* s) {
    int balance = 0;  // จำนวน '(' ที่ยังไม่ถูกปิด
    int additions = 0; // จำนวนที่ต้องเพิ่ม
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            balance++;  // เพิ่มการเปิดวงเล็บ
        } else if (s[i] == ')') {
            if (balance > 0) {
                balance--;  // ปิดวงเล็บที่เปิดอยู่
            } else {
                additions++; // ต้องเพิ่ม '('
            }
        }
    }
    
    // เพิ่ม ')' สำหรับวงเล็บที่เปิดแต่ยังไม่ปิด
    additions += balance;
    
    return additions;
}