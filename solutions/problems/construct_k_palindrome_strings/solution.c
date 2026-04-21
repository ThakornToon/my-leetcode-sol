bool canConstruct(char* s, int k) {
    int n = strlen(s);
    
    // ถ้า k > n ไม่สามารถสร้างได้ เพราะแต่ละ palindrome ต้องมีอย่างน้อย 1 ตัว
    if (k > n) {
        return false;
    }
    
    // นับความถี่ของตัวอักษร
    int freq[26] = {0};
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }
    
    // นับจำนวนตัวอักษรที่มีความถี่เป็นเลขคี่
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddCount++;
        }
    }
    
    // palindrome แต่ละอันสามารถมีตัวคี่ได้มากสุด 1 ตัว
    // ดังนั้น oddCount ต้องไม่เกิน k
    return oddCount <= k;
}