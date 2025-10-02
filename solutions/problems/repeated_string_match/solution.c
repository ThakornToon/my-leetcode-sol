// ฟังก์ชันตรวจสอบ substring แบบเขียนเอง
int isSubstring(char* haystack, char* needle) {
    int lenH = strlen(haystack);
    int lenN = strlen(needle);
    
    // ถ้า needle ยาวกว่า haystack เป็นไปไม่ได้ที่จะเป็น substring
    if (lenN > lenH) {
        return 0;
    }
    
    // ตรวจสอบทุกตำแหน่งเริ่มต้นที่เป็นไปได้
    for (int i = 0; i <= lenH - lenN; i++) {
        int found = 1;
        
        // ตรวจสอบทีละตัวอักษร
        for (int j = 0; j < lenN; j++) {
            if (haystack[i + j] != needle[j]) {
                found = 0;
                break;
            }
        }
        
        if (found) {
            return 1;
        }
    }
    
    return 0;
}

int repeatedStringMatch(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    // คำนวณจำนวนครั้งสูงสุดที่อาจต้องทำซ้ำ
    int maxRepeat = (lenB / lenA) + 2;
    
    // สร้าง buffer สำหรับเก็บสตริงที่ทำซ้ำ
    int maxLen = lenA * maxRepeat + 1;
    char* repeated = (char*)malloc(maxLen * sizeof(char));
    repeated[0] = '\0';
    
    for (int i = 0; i < maxRepeat; i++) {
        // เพิ่มสตริง a ต่อท้าย
        strcat(repeated, a);
        
        // ตรวจสอบว่า b เป็น substring ของ repeated หรือไม่ (ใช้ฟังก์ชันเราเอง)
        if (isSubstring(repeated, b)) {
            free(repeated);
            return i + 1;
        }
    }
    
    free(repeated);
    return -1;
}