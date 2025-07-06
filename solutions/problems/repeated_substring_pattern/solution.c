bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);
    if (len == 1) {
        return false;
    }
    char* temp = (char*)malloc((len / 2 + 1) * sizeof(char));
    for (int i = 1; i <= len / 2; i++) {
        if (len % i != 0) continue;

        strncpy(temp, s, i);
        temp[i] = '\0';
        
        bool match = true;
        for (int j = i; j <= len - i; j += i) {
            if (strncmp(s + j, temp, i) != 0) {
                match = false;
                break;
            }
        }
        
        if (match) {
            free(temp);
            return true;
        }
    }   
    free(temp);
    return false;
}