char* toGoatLatin(char* sentence) {
    char* result = malloc(5000);
    result[0] = '\0';
    char* word = strtok(sentence, " ");
    int count = 1;
    
    while (word) {
        char first = tolower(word[0]);
        
        if (strchr("aeiou", first)) {
            // สระ
            strcat(result, word);
            strcat(result, "ma");
        } else {
            // พยัญชนะ
            strcat(result, word + 1);
            strncat(result, word, 1);
            strcat(result, "ma");
        }
        
        // เพิ่ม 'a'
        for (int i = 0; i < count; i++) {
            strcat(result, "a");
        }
        
        word = strtok(NULL, " ");
        if (word) strcat(result, " ");
        count++;
    }
    
    return result;
}