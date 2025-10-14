char* customSortString(char* order, char* s) {
    int count[26] = {0};
    int s_len = strlen(s);
    int order_len = strlen(order);
    
    // นับความถี่ของตัวอักษรใน s
    for (int i = 0; i < s_len; i++) {
        count[s[i] - 'a']++;
    }
    
    // สร้างผลลัพธ์
    char* result = malloc((s_len + 1) * sizeof(char));
    int idx = 0;
    
    // เพิ่มตัวอักษรตามลำดับใน order
    for (int i = 0; i < order_len; i++) {
        char c = order[i];
        while (count[c - 'a'] > 0) {
            result[idx++] = c;
            count[c - 'a']--;
        }
    }
    
    // เพิ่มตัวอักษรที่เหลือ (ที่ไม่ใช่ใน order)
    for (char c = 'a'; c <= 'z'; c++) {
        while (count[c - 'a'] > 0) {
            result[idx++] = c;
            count[c - 'a']--;
        }
    }
    
    result[idx] = '\0';
    return result;
}