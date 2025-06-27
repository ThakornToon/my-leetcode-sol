int maxProduct(char** words, int wordsSize) {
    int* masks = (int*)calloc(wordsSize, sizeof(int));
    
    // สร้าง bitmask สำหรับแต่ละคำ
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        for (int j = 0; word[j] != '\0'; j++) {
            masks[i] |= 1 << (word[j] - 'a');
        }
    }
    
    int max_prod = 0;
    // เปรียบเทียบทุกคู่ของคำ
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if ((masks[i] & masks[j]) == 0) { // ไม่มีตัวอักษรร่วมกัน
                int current_prod = strlen(words[i]) * strlen(words[j]);
                if (current_prod > max_prod) {
                    max_prod = current_prod;
                }
            }
        }
    }
    
    free(masks);
    return max_prod;
}