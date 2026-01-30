char* minRemoveToMakeValid(char* s) {
    int n = strlen(s);
    
    // ใช้ stack เก็บ index ของ '('
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    
    // ใช้ array บอกตำแหน่งที่ต้องลบ
    bool* remove = (bool*)calloc(n, sizeof(bool));
    
    // 1. วนผ่านสตริงเพื่อหา parentheses ที่ไม่สมดุล
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            // เพิ่ม '(' ลง stack
            stack[++top] = i;
        } else if (s[i] == ')') {
            if (top >= 0) {
                // มี '(' คู่กัน
                top--;
            } else {
                // ไม่มี '(' คู่กัน → ต้องลบ
                remove[i] = true;
            }
        }
        // อักขระอื่นไม่ต้องทำอะไร
    }
    
    // 2. '(' ที่เหลือใน stack ต้องลบทั้งหมด
    while (top >= 0) {
        remove[stack[top--]] = true;
    }
    
    // 3. สร้างสตริงผลลัพธ์
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
        if (!remove[i]) {
            result[idx++] = s[i];
        }
    }
    result[idx] = '\0';
    
    // 4. คืนหน่วยความจำ
    free(stack);
    free(remove);
    
    return result;
}