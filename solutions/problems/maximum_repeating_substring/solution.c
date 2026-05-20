bool isRepeating(char* sequence, char* word, int k) {
    // สร้าง string word ซ้ำ k ครั้ง
    int wordLen = strlen(word);
    int totalLen = wordLen * k;
    char* repeated = (char*)malloc((totalLen + 1) * sizeof(char));
    repeated[0] = '\0';
    
    for (int i = 0; i < k; i++) {
        strcat(repeated, word);
    }
    
    // ตรวจสอบว่า repeated เป็น substring ของ sequence หรือไม่
    bool result = (strstr(sequence, repeated) != NULL);
    free(repeated);
    return result;
}

int maxRepeating(char* sequence, char* word) {
    int maxK = 0;
    int seqLen = strlen(sequence);
    int wordLen = strlen(word);
    int maxPossibleK = seqLen / wordLen;
    
    for (int k = maxPossibleK; k >= 1; k--) {
        if (isRepeating(sequence, word, k)) {
            return k;
        }
    }
    
    return 0;
}