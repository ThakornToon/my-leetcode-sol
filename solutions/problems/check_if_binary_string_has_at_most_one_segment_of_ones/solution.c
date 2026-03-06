bool checkOnesSegment(char* s) {
    int len = strlen(s);
    int segmentCount = 0;
    int i = 0;
    
    while (i < len) {
        if (s[i] == '1') {
            segmentCount++;
            // ข้าม '1' ทั้งกลุ่ม
            while (i < len && s[i] == '1') {
                i++;
            }
            // ถ้าเจอกลุ่มที่สองแล้ว
            if (segmentCount > 1) {
                return false;
            }
        } else {
            i++;
        }
    }
    
    return true;

}