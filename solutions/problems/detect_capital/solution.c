bool detectCapitalUse(char* word) {
    int count = 0;
    int len = strlen(word);
    
    for (int i = 0; i < len; i++) {
        if (isupper(word[i])) {
            count++;
        }
    }
    
    return count == len || 
           count == 0 || 
           (count == 1 && isupper(word[0]));
}