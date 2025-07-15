/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    // สร้างตารางแป้นพิมพ์ (a-z)
    const int keyboard[26] = {
        2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 
        3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3
    };
    
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        
        // หาแถวของตัวอักษรตัวแรก
        int row = keyboard[tolower(word[0]) - 'a'];
        bool valid = true;
        
        // ตรวจสอบตัวอักษรที่เหลือ
        for (int j = 1; word[j] != '\0'; j++) {
            if (keyboard[tolower(word[j]) - 'a'] != row) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            result[*returnSize] = (char*)malloc(strlen(word) + 1);
            strcpy(result[*returnSize], word);
            (*returnSize)++;
        }
    }
    
    return result;
}