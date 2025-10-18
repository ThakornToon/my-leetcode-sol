int uniqueMorseRepresentations(char** words, int wordsSize) {
    // รหัสมอร์สสำหรับ a-z
    char* morse[26] = {
        ".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.",
        "---",".--.","--.-",".-.","...","-","..-",
        "...-",".--","-..-","-.--","--.."
    };
    
    // ใช้ array เก็บรหัสที่ไม่ซ้ำกัน (แบบง่ายๆ)
    char** uniqueCodes = (char**)malloc(wordsSize * sizeof(char*));
    int uniqueCount = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        // สร้างรหัสมอร์สสำหรับคำปัจจุบัน
        char morseCode[100] = "";
        
        for (int j = 0; words[i][j] != '\0'; j++) {
            strcat(morseCode, morse[words[i][j] - 'a']);
        }
        
        // ตรวจสอบว่าซ้ำหรือไม่
        int found = 0;
        for (int k = 0; k < uniqueCount; k++) {
            if (strcmp(uniqueCodes[k], morseCode) == 0) {
                found = 1;
                break;
            }
        }
        
        // ถ้าไม่ซ้ำ ให้เพิ่มเข้าไป
        if (!found) {
            uniqueCodes[uniqueCount] = (char*)malloc(strlen(morseCode) + 1);
            strcpy(uniqueCodes[uniqueCount], morseCode);
            uniqueCount++;
        }
    }
    
    // คืน memory
    for (int i = 0; i < uniqueCount; i++) {
        free(uniqueCodes[i]);
    }
    free(uniqueCodes);
    
    return uniqueCount;
}