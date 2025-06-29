int countSegments(char* s) {
    int count = 0;
    int inSegment = 0;
    
    while (*s) {
        if (*s != ' ' && !inSegment) {
            count++;
            inSegment = 1;
        } else if (*s == ' ') {
            inSegment = 0;
        }
        s++;
    }
    
    return count;
}