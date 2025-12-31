int maxNumberOfBalloons(char* text) {
    // ใช้ array ขนาด 26 สำหรับตัวอักษร a-z
    int count[26] = {0};
    
    // นับความถี่ของแต่ละตัวอักษร
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        count[text[i] - 'a']++;
    }
    
    // ต้องการ: b=1, a=1, l=2, o=2, n=1
    // หาค่าน้อยที่สุดที่สามารถสร้าง "balloon" ได้
    
    int result = INT_MAX;
    
    // 'b' (index 1)
    if (count[1] < result) result = count[1];
    
    // 'a' (index 0)
    if (count[0] < result) result = count[0];
    
    // 'l' (index 11) - ต้องการ 2 ตัวต่อคำ
    if (count[11] / 2 < result) result = count[11] / 2;
    
    // 'o' (index 14) - ต้องการ 2 ตัวต่อคำ
    if (count[14] / 2 < result) result = count[14] / 2;
    
    // 'n' (index 13)
    if (count[13] < result) result = count[13];
    
    return result;
}