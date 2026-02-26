int numSteps(char* s) {
    int n = strlen(s);
    int steps = 0;
    int carry = 0;  // carry จากการบวก 1
    
    // เริ่มจากขวาไปซ้าย (ไม่นับตัวสุดท้าย)
    for (int i = n - 1; i > 0; i--) {
        // digit = s[i] - '0' + carry
        int digit = (s[i] - '0') + carry;
        
        if (digit == 0) {
            // กรณี: digit 0 (even) → หาร 2
            steps++;
            // carry คงเดิม (0)
        } else if (digit == 1) {
            // กรณี: digit 1 (odd) → บวก 1 (ได้ 2) แล้วหาร 2
            steps += 2;  // +1 และ /2
            carry = 1;   // บวก 1 ทำให้เกิด carry
        } else { // digit == 2 (เกิดจาก 1 + carry)
            // กรณี: digit 2 (even) → หาร 2 ได้ 1
            steps++;     // /2
            carry = 1;   // carry คงเดิม (เพราะ 2/2 = 1)
        }
    }
    
    // ตัวสุดท้าย (bit ซ้ายสุด) + carry
    int last = (s[0] - '0') + carry;
    if (last == 2) {
        // 10 → ต้องหาร 2 อีกครั้ง (กลายเป็น 1)
        steps++;
    }
    // ถ้า last == 1: จบแล้ว (เป็น 1)
    // ถ้า last == 0: ไม่เกิดขึ้นเพราะเลข > 0
    
    return steps;
}