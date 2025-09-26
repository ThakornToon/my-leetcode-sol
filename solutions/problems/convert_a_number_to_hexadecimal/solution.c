char* toHex(int num) {
    if (num == 0) {
        char* result = (char*)malloc(2);
        strcpy(result, "0");
        return result;
    }
    
    unsigned int n = (unsigned int)num; // ใช้ unsigned เพื่อจัดการกับจำนวนลบ
    char* hexChars = "0123456789abcdef";
    char buffer[9] = {0}; // 32-bit = 8 หลัก + null terminator
    int index = 7;
    
    while (n > 0) {
        int remainder = n % 16;
        buffer[index--] = hexChars[remainder];
        n /= 16;
    }
    
    // คัดลอกเฉพาะส่วนที่ใช้
    char* result = (char*)malloc(9);
    strcpy(result, buffer + index + 1); // ขยับจุดเริ่มคัดลอก
    return result;
}