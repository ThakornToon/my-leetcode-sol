/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** commonChars(char** words, int wordsSize, int* returnSize) {
    // เก็บ frequency ต่ำสุดสำหรับแต่ละตัวอักษร
    int minFreq[26];
    // เริ่มต้นด้วยค่าสูงสุด
    for (int i = 0; i < 26; i++) {
        minFreq[i] = INT_MAX;
    }
    
    // frequency ชั่วคราวสำหรับแต่ละคำ
    int tempFreq[26];
    
    for (int i = 0; i < wordsSize; i++) {
        // รีเซ็ต tempFreq
        memset(tempFreq, 0, sizeof(tempFreq));
        
        // นับความถี่ของตัวอักษรในคำปัจจุบัน
        char* word = words[i];
        for (int j = 0; word[j] != '\0'; j++) {
            tempFreq[word[j] - 'a']++;
        }
        
        // อัพเดต minFreq
        for (int k = 0; k < 26; k++) {
            if (tempFreq[k] < minFreq[k]) {
                minFreq[k] = tempFreq[k];
            }
        }
    }
    
    // คำนวณขนาดผลลัพธ์ทั้งหมด
    int totalChars = 0;
    for (int i = 0; i < 26; i++) {
        totalChars += minFreq[i];
    }
    
    // จองหน่วยความจำสำหรับผลลัพธ์
    char** result = (char**)malloc(totalChars * sizeof(char*));
    int index = 0;
    
    // สร้างผลลัพธ์
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < minFreq[i]; j++) {
            result[index] = (char*)malloc(2 * sizeof(char));
            result[index][0] = 'a' + i;
            result[index][1] = '\0';
            index++;
        }
    }
    
    *returnSize = totalChars;
    return result;
}