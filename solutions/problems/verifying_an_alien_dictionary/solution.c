bool isAlienSorted(char** words, int wordsSize, char* order) {
    // สร้าง mapping จาก character ไปยัง order index
    int orderMap[26];
    for (int i = 0; i < 26; i++) {
        orderMap[order[i] - 'a'] = i;
    }
    
    // เปรียบเทียบทีละคู่ของ words
    for (int i = 0; i < wordsSize - 1; i++) {
        char* word1 = words[i];
        char* word2 = words[i + 1];
        
        int len1 = strlen(word1);
        int len2 = strlen(word2);
        int minLen = len1 < len2 ? len1 : len2;
        
        bool foundDifference = false;
        
        // เปรียบเทียบทีละตัวอักษร
        for (int j = 0; j < minLen; j++) {
            char c1 = word1[j];
            char c2 = word2[j];
            
            if (c1 != c2) {
                // ตรวจสอบ order
                if (orderMap[c1 - 'a'] > orderMap[c2 - 'a']) {
                    return false;  // ไม่เรียงลำดับ
                }
                foundDifference = true;
                break;
            }
        }
        
        // ถ้าตัวอักษรทั้งหมดเหมือนกัน แต่ word1 ยาวกว่า word2
        if (!foundDifference && len1 > len2) {
            return false;
        }
    }
    
    return true;
}