int minInsertions(char* s) {
    int left = 0;
    int insertions = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            // เจอ ')'
            if (i + 1 < strlen(s) && s[i + 1] == ')') {
                // มี '))'
                i++;
            } else {
                // ต้องแทรก ')'
                insertions++;
            }
            
            if (left > 0) {
                left--;
            } else {
                // แทรก '('
                insertions++;
            }
        }
    }
    
    // แทรก '))'
    insertions += left * 2;
    return insertions;
}