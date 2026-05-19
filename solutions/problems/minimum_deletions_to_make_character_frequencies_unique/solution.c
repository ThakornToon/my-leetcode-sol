int minDeletions(char* s) {
    int freq[26] = {0};
    int n = strlen(s);
    
    // นับความถี่ของแต่ละตัวอักษร
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }
    
    // เรียงลำดับความถี่จากมากไปน้อย (bubble sort เลย เพราะ n=26)
    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (freq[i] < freq[j]) {
                int temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }
    
    bool used[100001] = {false}; // ความถี่สูงสุดไม่เกิน n
    int deletions = 0;
    
    for (int i = 0; i < 26; i++) {
        int currentFreq = freq[i];
        if (currentFreq == 0) continue;
        
        // ลดความถี่ลงจนกว่าจะเจอค่าที่ไม่ถูกใช้
        while (currentFreq > 0 && used[currentFreq]) {
            currentFreq--;
            deletions++;
        }
        
        // ถ้ายังมีค่าความถี่เหลือ ให้ mark ว่าใช้แล้ว
        if (currentFreq > 0) {
            used[currentFreq] = true;
        }
    }
    
    return deletions;
}