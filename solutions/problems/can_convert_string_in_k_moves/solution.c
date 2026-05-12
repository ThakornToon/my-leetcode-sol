#define MAX_SHIFT 26

bool canConvertString(char* s, char* t, int k) {
    int len = strlen(s);
    
    // ถ้าความยาวไม่เท่ากัน ไม่สามารถแปลงได้
    if (len != strlen(t)) {
        return false;
    }
    
    // นับจำนวนครั้งที่ต้องการใช้ shift แต่ละค่า (1-25)
    int shifts[MAX_SHIFT] = {0};
    
    for (int i = 0; i < len; i++) {
        int diff = (t[i] - s[i] + MAX_SHIFT) % MAX_SHIFT;
        if (diff == 0) continue;  // ไม่ต้องเปลี่ยนแปลง
        shifts[diff]++;
        
        // ต้องการใช้ shift = diff
        // ใช้ได้ครั้งที่: diff, diff+26, diff+52, ...
        int required = diff + (shifts[diff] - 1) * MAX_SHIFT;
        
        // ตรวจสอบว่าครั้งที่ต้องการ <= k หรือไม่
        if (required > k) {
            return false;
        }
    }
    
    return true;
}