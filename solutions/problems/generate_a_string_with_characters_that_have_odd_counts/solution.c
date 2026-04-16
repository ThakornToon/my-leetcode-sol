char* generateTheString(int n) {
    char* result = (char*)malloc((n + 1) * sizeof(char));
    
    if (n % 2 == 1) {
        // n เป็นคี่: ใช้ 'a' ทั้งหมด n ตัว
        memset(result, 'a', n);
    } else {
        // n เป็นคู่: ใช้ 'a' n-1 ตัว + 'b' 1 ตัว
        memset(result, 'a', n - 1);
        result[n - 1] = 'b';
    }
    
    result[n] = '\0';
    return result;
}