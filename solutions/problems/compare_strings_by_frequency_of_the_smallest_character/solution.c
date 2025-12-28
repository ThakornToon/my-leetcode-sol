/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ฟังก์ชันคำนวณ f(s)
int calculateF(char* s) {
    char smallest = 'z';
    int count = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c < smallest) {
            smallest = c;
            count = 1;
        } else if (c == smallest) {
            count++;
        }
    }
    
    return count;
}

int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize) {
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    
    // f(s) ≤ 10 (เพราะ string ยาวไม่เกิน 10)
    int freqCount[11] = {0};  // index 1-10
    
    // คำนวณ frequency สำหรับ words
    for (int i = 0; i < wordsSize; i++) {
        int f = calculateF(words[i]);
        freqCount[f]++;
    }
    
    // สร้าง suffix sum
    int suffixSum[12] = {0};  // ขนาด 12 เพื่อให้ suffixSum[11]=0
    for (int i = 10; i >= 1; i--) {
        suffixSum[i] = suffixSum[i + 1] + freqCount[i];
    }
    
    // สำหรับแต่ละ query
    for (int i = 0; i < queriesSize; i++) {
        int queryF = calculateF(queries[i]);
        // ต้องการจำนวนคำที่มี f > queryF
        if (queryF < 10) {
            result[i] = suffixSum[queryF + 1];
        } else {
            result[i] = 0;  // queryF = 10 ไม่มีคำไหนมากกว่า
        }
    }
    
    return result;
}