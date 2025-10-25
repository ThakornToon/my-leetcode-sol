#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    // Convert to lowercase and replace punctuation with spaces
    for (int i = 0; paragraph[i]; i++) {
        if (isalpha(paragraph[i])) {
            paragraph[i] = tolower(paragraph[i]);
        } else {
            paragraph[i] = ' ';
        }
    }
    
    // Count word frequency
    WordCount wordCounts[MAX_WORDS] = {0};
    int wordCountSize = 0;
    
    char* token = strtok(paragraph, " ");
    while (token != NULL) {
        // Check if word is banned
        bool isBanned = false;
        for (int i = 0; i < bannedSize; i++) {
            if (strcmp(token, banned[i]) == 0) {
                isBanned = true;
                break;
            }
        }
        
        if (!isBanned && strlen(token) > 0) {
            // Find or add word in wordCounts
            bool found = false;
            for (int i = 0; i < wordCountSize; i++) {
                if (strcmp(wordCounts[i].word, token) == 0) {
                    wordCounts[i].count++;
                    found = true;
                    break;
                }
            }
            
            if (!found && wordCountSize < MAX_WORDS) {
                strcpy(wordCounts[wordCountSize].word, token);
                wordCounts[wordCountSize].count = 1;
                wordCountSize++;
            }
        }
        
        token = strtok(NULL, " ");
    }
    
    // Find most frequent word
    int maxCount = 0;
    char* result = malloc(MAX_WORD_LENGTH);
    
    for (int i = 0; i < wordCountSize; i++) {
        if (wordCounts[i].count > maxCount) {
            maxCount = wordCounts[i].count;
            strcpy(result, wordCounts[i].word);
        }
    }
    
    return result;
}