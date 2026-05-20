bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i1 = 0, i2 = 0; // index ของ word
    int j1 = 0, j2 = 0; // index ของ char ใน word
    
    while (i1 < word1Size && i2 < word2Size) {
        char c1 = word1[i1][j1];
        char c2 = word2[i2][j2];
        
        if (c1 != c2) {
            return false;
        }
        
        j1++;
        j2++;
        
        if (word1[i1][j1] == '\0') {
            i1++;
            j1 = 0;
        }
        
        if (word2[i2][j2] == '\0') {
            i2++;
            j2 = 0;
        }
    }
    
    return i1 == word1Size && i2 == word2Size;

}