/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define ALPHABET_SIZE 26

// ฟังก์ชันนับความถี่ของตัวอักษรในคำ
void countFrequency(const char* word, int* freq) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freq[i] = 0;
    }
    
    for (int i = 0; word[i] != '\0'; i++) {
        freq[word[i] - 'a']++;
    }
}

char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    // สร้าง array สำหรับเก็บความถี่สูงสุดจาก words2
    int maxFreq[ALPHABET_SIZE] = {0};
    
    // คำนวณความถี่สูงสุดสำหรับแต่ละตัวอักษรจาก words2
    for (int i = 0; i < words2Size; i++) {
        int currentFreq[ALPHABET_SIZE] = {0};
        countFrequency(words2[i], currentFreq);
        
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (currentFreq[j] > maxFreq[j]) {
                maxFreq[j] = currentFreq[j];
            }
        }
    }
    
    // ตรวจสอบว่า words1 แต่ละคำเป็น universal หรือไม่
    bool* isUniversal = (bool*)malloc(words1Size * sizeof(bool));
    int count = 0;
    
    for (int i = 0; i < words1Size; i++) {
        int wordFreq[ALPHABET_SIZE] = {0};
        countFrequency(words1[i], wordFreq);
        
        bool valid = true;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (wordFreq[j] < maxFreq[j]) {
                valid = false;
                break;
            }
        }
        
        isUniversal[i] = valid;
        if (valid) count++;
    }
    
    // สร้างผลลัพธ์
    char** result = (char**)malloc(count * sizeof(char*));
    int index = 0;
    
    for (int i = 0; i < words1Size; i++) {
        if (isUniversal[i]) {
            result[index] = (char*)malloc((strlen(words1[i]) + 1) * sizeof(char));
            strcpy(result[index], words1[i]);
            index++;
        }
    }
    
    free(isUniversal);
    *returnSize = count;
    return result;
}