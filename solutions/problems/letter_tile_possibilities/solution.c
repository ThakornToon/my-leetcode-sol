void backtrack(int* count, int* freq) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            // Use this character
            (*count)++;
            freq[i]--;
            
            // Recurse
            backtrack(count, freq);
            
            // Backtrack
            freq[i]++;
        }
    }
}

int numTilePossibilities(char* tiles) {
    int freq[26] = {0};
    for (int i = 0; tiles[i] != '\0'; i++) {
        freq[tiles[i] - 'A']++;
    }
    
    int count = 0;
    backtrack(&count, freq);
    
    return count;
}