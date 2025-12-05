char* decodeAtIndex(char* s, int k) {
    long long length = 0;
    
    // คำนวณ total length
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            length *= (s[i] - '0');
        } else {
            length++;
        }
    }
    
    // เดินจากหลังมาหน้า
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        char c = s[i];
        
        if (isdigit(c)) {
            int d = c - '0';
            length /= d;
            k %= length;
            if (k == 0) k = length;
        } else {
            if (k == length) {
                char* result = (char*)malloc(2 * sizeof(char));
                result[0] = c;
                result[1] = '\0';
                return result;
            }
            length--;
        }
    }
    
    // ไม่ควรมาถึงตรงนี้
    char* result = (char*)malloc(1 * sizeof(char));
    result[0] = '\0';
    return result;
}