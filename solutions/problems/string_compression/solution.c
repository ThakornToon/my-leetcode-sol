int compress(char* chars, int charsSize) {
    int write = 0;
    int read = 0;
    int count = 0;
    char prev = chars[0];
    
    while (read <= charsSize) {
        if (read < charsSize && chars[read] == prev) {
            count++;
            read++;
        } else {
            chars[write++] = prev;
            
            if (count > 1) {
                char num[10];
                sprintf(num, "%d", count);
                for (char* p = num; *p; p++) {
                    chars[write++] = *p;
                }
            }
            
            if (read < charsSize) {
                prev = chars[read];
                count = 0;
            } else {
                break;
            }
        }
    }
    
    return write;
}