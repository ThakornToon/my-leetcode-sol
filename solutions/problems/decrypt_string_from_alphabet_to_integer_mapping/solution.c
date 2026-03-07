char* freqAlphabets(char* s) {
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char));  // จองพื้นที่เผื่อ
    int resultIndex = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '#') {
            // อ่าน 2 ตัวข้างหน้า (i-2, i-1)
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            result[resultIndex++] = 'a' + (num - 1);
            i -= 2;  // ข้ามไป 3 ตัว (รวม #)
        } else {
            // อ่านตัวเดียว
            int num = s[i] - '0';
            result[resultIndex++] = 'a' + (num - 1);
        }
    }
    
    // ปิดท้าย string
    result[resultIndex] = '\0';
    
    // reverse string เพราะเราอ่านจากขวาไปซ้าย
    for (int i = 0; i < resultIndex / 2; i++) {
        char temp = result[i];
        result[i] = result[resultIndex - 1 - i];
        result[resultIndex - 1 - i] = temp;
    }
    
    return result;
}