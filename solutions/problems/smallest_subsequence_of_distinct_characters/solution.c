char* smallestSubsequence(char* s) {
    int count[26] = {0};
    bool inStack[26] = {false};
    char* stack = (char*)malloc(strlen(s) + 1);
    int top = -1;
    
    // นับความถี่ของแต่ละตัวอักษร
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
    }
    
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        count[c - 'a']--;  // ลดความถี่ของตัวอักษรปัจจุบัน
        
        if (inStack[c - 'a']) continue;  // ข้ามถ้ามีใน Stack แล้ว
        
        // นำตัวอักษรใน Stack ที่มากกว่าออกถ้ายังมีเหลือในสตริง
        while (top >= 0 && c < stack[top] && count[stack[top] - 'a'] > 0) {
            inStack[stack[top] - 'a'] = false;
            top--;
        }
        
        stack[++top] = c;
        inStack[c - 'a'] = true;
    }
    
    // สร้างสตริงผลลัพธ์จาก Stack
    stack[top + 1] = '\0';
    return stack;
}