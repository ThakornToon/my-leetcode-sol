int findLUSlength(char* a, char* b) {
    if (strcmp(a, b) == 0) {
        return -1;
    }
    int lenA = strlen(a);
    int lenB = strlen(b);
    return lenA > lenB ? lenA : lenB;
}