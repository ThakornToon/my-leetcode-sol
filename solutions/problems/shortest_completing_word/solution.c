char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int licenseCount[26] = {0};
    
    // Build frequency map from licensePlate
    for (int i = 0; licensePlate[i]; i++) {
        if (isalpha(licensePlate[i])) {
            licenseCount[tolower(licensePlate[i]) - 'a']++;
        }
    }
    
    char* result = NULL;
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int wordCount[26] = {0};
        
        // Build frequency map for current word
        for (int j = 0; word[j]; j++) {
            wordCount[word[j] - 'a']++;
        }
        
        // Check if word contains all required letters
        int valid = 1;
        for (int j = 0; j < 26; j++) {
            if (wordCount[j] < licenseCount[j]) {
                valid = 0;
                break;
            }
        }
        
        // Update result
        if (valid && (result == NULL || strlen(word) < strlen(result))) {
            result = word;
        }
    }
    
    return result;
}