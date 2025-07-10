int* memo;

bool backtrack(int maxNumber, int desiredTotal, int* used) {
    // สร้าง key จาก bitmask สถานะ used
    int key = 0;
    for (int i = 0; i < maxNumber; i++) {
        if (used[i]) {
            key |= (1 << i);
        }
    }
    
    // ตรวจสอบ memo
    if (memo[key] != -1) { // -1 เป็นค่าที่ยังไม่ได้คำนวณ
        return memo[key];
    }

    // ไล่ดูตัวเลขที่ยังไม่เคยใช้
    for (int i = 1; i <= maxNumber; i++) {
        if (!used[i-1]) {
            used[i-1] = 1;
            
            // ถ้าเลือกตัวนี้แล้วชนะ หรือทำให้คู่ต่อสู้แพ้
            if (desiredTotal - i <= 0 || !backtrack(maxNumber, desiredTotal - i, used)) {
                used[i-1] = 0;
                memo[key] = true;
                return true;
            }
            
            used[i-1] = 0;
        }
    }
    
    memo[key] = false;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    // ตรวจสอบเงื่อนไขเบื้องต้น
    if (desiredTotal <= 0) return true;
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
    if (maxChoosableInteger >= desiredTotal) return true;

    // เตรียม memo โดยใช้ key เป็น index โดยตรง
    int memoSize = 1 << maxChoosableInteger; // ความเป็นไปได้ทั้งหมด
    memo = (int*)malloc(memoSize * sizeof(int));
    memset(memo, -1, memoSize * sizeof(int)); // กำหนดค่าเริ่มต้นเป็น -1 (ยังไม่ได้คำนวณ)
    
    int* used = (int*)calloc(maxChoosableInteger, sizeof(int)); // เก็บสถานะแต่ละตัวเลขว่าถูกใช้รึยัง
    bool result = backtrack(maxChoosableInteger, desiredTotal, used);
    
    free(used);
    free(memo);
    return result;
}