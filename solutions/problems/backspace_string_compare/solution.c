bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;
    int skip_s = 0, skip_t = 0;
    
    while (i >= 0 || j >= 0) {
        // หาตัวอักษรถัดไปของ s ที่ไม่ถูกลบ
        while (i >= 0) {
            if (s[i] == '#') {
                skip_s++;
                i--;
            } else if (skip_s > 0) {
                skip_s--;
                i--;
            } else {
                break;
            }
        }
        
        // หาตัวอักษรถัดไปของ t ที่ไม่ถูกลบ
        while (j >= 0) {
            if (t[j] == '#') {
                skip_t++;
                j--;
            } else if (skip_t > 0) {
                skip_t--;
                j--;
            } else {
                break;
            }
        }
        
        // เปรียบเทียบตัวอักษร
        if (i >= 0 && j >= 0) {
            if (s[i] != t[j]) {
                return false;
            }
        } else if (i >= 0 || j >= 0) {
            // หนึ่งสตริงจบก่อนอีกสตริง
            return false;
        }
        
        i--;
        j--;
    }
    
    return true;
}