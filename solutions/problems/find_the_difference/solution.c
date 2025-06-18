char findTheDifference(char* s, char* t) {
    char letter = 0;
    for (int i = 0; i < strlen(s) || i < strlen(t); i++) {
        letter += (t[i] - s[i]);
    }
    return letter;
}