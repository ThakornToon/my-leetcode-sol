char* licenseKeyFormatting(char* s, int k) {
    // นับจำนวนตัวอักษรที่ต้องใช้ (ไม่รวม '-')
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '-') len++;
    }
    
    if (len == 0) return "";
    
    // คำนวณจำนวนขีดกลางที่ต้องเพิ่ม
    int dashes = (len - 1) / k;
    int total_len = len + dashes;
    char* result = (char*)malloc((total_len + 1) * sizeof(char));
    result[total_len] = '\0';
    
    int count = 0;
    int pos = total_len - 1;
    
    // เริ่มจากท้ายสตริงเดิมไปหน้าสุด
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] != '-') {
            result[pos--] = toupper(s[i]);
            count++;
            
            // ใส่ '-' ทุก k ตัวอักษร (แต่ไม่ใช่ตัวแรก)
            if (count % k == 0 && pos >= 0) {
                result[pos--] = '-';
            }
        }
    }
    
    return result;
}