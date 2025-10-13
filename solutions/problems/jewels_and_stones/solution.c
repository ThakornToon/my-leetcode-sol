int numJewelsInStones(char* jewels, char* stones) {
    int jewelSet[128] = {0};  // ASCII table มี 128 ตัว
    int count = 0;
    
    // เก็บอัญมณีใน set
    for (int i = 0; jewels[i] != '\0'; i++) {
        jewelSet[jewels[i]] = 1;
    }
    
    // นับก้อนหินที่เป็นอัญมณี
    for (int i = 0; stones[i] != '\0'; i++) {
        if (jewelSet[stones[i]]) {
            count++;
        }
    }
    
    return count;
}