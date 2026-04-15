#define MIN(a, b) ((a) < (b) ? (a) : (b))

int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int minDistance = INT_MAX;
    int found = 0;
    
    // หาทุกตำแหน่งที่มีค่าเท่ากับ target
    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], target) == 0) {
            found = 1;
            
            // คำนวณระยะทางไปข้างหน้า
            int forward = (i - startIndex + wordsSize) % wordsSize;
            // คำนวณระยะทางไปข้างหลัง
            int backward = (startIndex - i + wordsSize) % wordsSize;
            
            int distance = MIN(forward, backward);
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
    }
    
    return found ? minDistance : -1;
}