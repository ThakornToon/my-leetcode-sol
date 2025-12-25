

char * alphabetBoardPath(char * target){
    char* result = malloc(1000 * sizeof(char));
    int idx = 0;
    
    int r = 0, c = 0;  // ตำแหน่งปัจจุบัน
    
    for (int i = 0; target[i] != '\0'; i++) {
        int ch = target[i] - 'a';
        int tr = ch / 5;
        int tc = ch % 5;
        
        // ซ้าย/ขวา ก่อน (เว้นแต่จะอยู่ที่ z)
        if (r == 5 && c == 0) {
            // จาก z: ขึ้นก่อน
            while (r > tr) {
                result[idx++] = 'U';
                r--;
            }
        }
        
        // ซ้าย/ขวา
        while (c > tc) {
            result[idx++] = 'L';
            c--;
        }
        while (c < tc) {
            result[idx++] = 'R';
            c++;
        }
        
        // ขึ้น/ลง
        while (r > tr) {
            result[idx++] = 'U';
            r--;
        }
        while (r < tr) {
            result[idx++] = 'D';
            r++;
        }
        
        result[idx++] = '!';
    }
    
    result[idx] = '\0';
    return result;
}