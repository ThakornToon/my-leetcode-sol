// ฟังก์ชันแปลงจำนวนเป็น binary string
void toBinary(int num, char* buffer) {
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    
    int i = 0;
    while (num > 0) {
        buffer[i++] = (num % 2) + '0';
        num /= 2;
    }
    buffer[i] = '\0';
    
    // reverse string
    for (int j = 0; j < i/2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i-1-j];
        buffer[i-1-j] = temp;
    }
}

// ฟังก์ชันตรวจสอบ substring
bool isSubstring(const char* s, const char* binary) {
    return strstr(s, binary) != NULL;
}

bool queryString(const char* s, int n) {
    int max_len = 0;
    int temp = n;
    while (temp > 0) {
        max_len++;
        temp >>= 1;
    }
    
    if (strlen(s) < max_len) {
        return false;
    }
    
    char binary[33]; // 32-bit + null terminator
    
    // ตรวจสอบทุกจำนวนจาก 1 ถึง n
    for (int i = 1; i <= n; i++) {
        toBinary(i, binary);
        
        if (!isSubstring(s, binary)) {
            return false;
        }
    }
    
    return true;
}