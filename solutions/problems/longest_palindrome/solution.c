int longestPalindrome(char* s) {
    int char_counts[58] = {0}; // ASCII ทั้งหมด
    int length = 0;
    bool has_odd = false;
    
    // นับความถี่ของแต่ละตัวอักษร
    for (int i = 0; s[i] != '\0'; i++) {
        char_counts[s[i] - 'A']++;
    }
    
    // คำนวณความยาวพาลินโดรม
    for (int i = 0; i < 58; i++) {
        if (char_counts[i] % 2 == 0) {
            length += char_counts[i];
        } else {
            length += char_counts[i] - 1;
            has_odd = true;
        }
    }
    
    // เพิ่ม 1 ถ้ามีตัวอักษรที่ปรากฏจำนวนคี่ครั้ง
    return has_odd ? length + 1 : length;
}