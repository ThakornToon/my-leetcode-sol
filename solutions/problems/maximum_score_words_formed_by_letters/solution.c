#define ALPHABET_SIZE 26

// ตรวจสอบว่าสามารถใช้คำนี้ได้หรือไม่ (มีตัวอักษรพอ)
int canUseWord(char* word, int* freq) {
    int tempFreq[ALPHABET_SIZE] = {0};
    
    // นับตัวอักษรที่ต้องการ
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        tempFreq[idx]++;
    }
    
    // ตรวจสอบว่ามีพอหรือไม่
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (tempFreq[i] > freq[i]) {
            return 0;
        }
    }
    
    return 1;
}

// คำนวณคะแนนของคำ
int getWordScore(char* word, int* score) {
    int total = 0;
    for (int i = 0; word[i]; i++) {
        total += score[word[i] - 'a'];
    }
    return total;
}

// ใช้คำ (ลด frequency)
void useWord(char* word, int* freq) {
    for (int i = 0; word[i]; i++) {
        freq[word[i] - 'a']--;
    }
}

// คืนคำ (เพิ่ม frequency กลับ)
void returnWord(char* word, int* freq) {
    for (int i = 0; word[i]; i++) {
        freq[word[i] - 'a']++;
    }
}

void backtrack(char** words, int wordsSize, int* freq, int* score, 
               int index, int currentScore, int* maxScore) {
    // อัปเดตคะแนนสูงสุด
    if (currentScore > *maxScore) {
        *maxScore = currentScore;
    }
    
    // ฐาน: ตรวจสอบครบทุกคำแล้ว
    if (index == wordsSize) {
        return;
    }
    
    // 1. ไม่เลือกคำนี้
    backtrack(words, wordsSize, freq, score, index + 1, currentScore, maxScore);
    
    // 2. เลือกคำนี้ (ถ้าสามารถใช้ได้)
    if (canUseWord(words[index], freq)) {
        int wordScore = getWordScore(words[index], score);
        useWord(words[index], freq);
        backtrack(words, wordsSize, freq, score, index + 1, 
                  currentScore + wordScore, maxScore);
        returnWord(words[index], freq);  // backtrack
    }
}

int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize) {
    // นับความถี่ของตัวอักษรที่มี
    int freq[ALPHABET_SIZE] = {0};
    for (int i = 0; i < lettersSize; i++) {
        freq[letters[i] - 'a']++;
    }
    
    int maxScore = 0;
    backtrack(words, wordsSize, freq, score, 0, 0, &maxScore);
    
    return maxScore;
}