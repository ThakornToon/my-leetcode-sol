/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    *returnSize = 0;
  
    
    int* result = (int*)malloc(sLen * sizeof(int));
    int pCount[26] = {0};
    int sCount[26] = {0};
    
    // นับความถี่ของตัวอักษรใน p
    for (int i = 0; i < pLen; i++) {
        pCount[p[i] - 'a']++;
    }
    
    // เริ่ม sliding window
    for (int i = 0; i < sLen; i++) {
        // เพิ่มตัวอักษรปัจจุบันใน window
        sCount[s[i] - 'a']++;
        
        // ถ้า window มีขนาดใหญ่เกิน ให้ลบตัวอักษรที่ออกจาก window
        if (i >= pLen) {
            sCount[s[i - pLen] - 'a']--;
        }
        
        // เปรียบเทียบความถี่
        int match = 1;
        for (int j = 0; j < 26; j++) {
            if (sCount[j] != pCount[j]) {
                match = 0;
                break;
            }
        }
        
        if (match) {
            result[(*returnSize)++] = i - pLen + 1;
        }
    }
    
    return result;
}