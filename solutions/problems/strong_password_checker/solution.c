int max(int a, int b) {
    return (a >= b) ? a : b;
}

int min(int a, int b) {
    return (a <= b) ? a : b;
}

int strongPasswordChecker(char* password) {
    int hasLower = 0;
    int hasUpper = 0;
    int hasDig = 0;
    int charLen = strlen(password);
    for (int i = 0; i < charLen; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDig = 1;
        }
    }

    int missingTypes = 3 - (hasLower + hasUpper + hasDig);
    int repeats[50] = {0}; // store length of each repeating sequence
    int repeatCount = 0;
    int i = 0;
    while (i < charLen) {
        int j = i;
        while (j < charLen && password[j] == password[i]) {
            j++;
        }
        if (j - i >= 3) {
            repeats[repeatCount++] = j - i;
        }
        i = j;
    }


    if (charLen < 6) {
        return max(6 - charLen, missingTypes);
    } 
    else if (charLen <= 20) {
        int replace = 0;
        for (int k = 0; k < repeatCount; k++) {
            replace += repeats[k] / 3;
        }
        return max(replace, missingTypes);
    } else {
        int overLen = charLen - 20;
        int deleteCount = overLen;
        
        // First, use deletions to break repeating sequences efficiently
        for (int k = 0; k < repeatCount && overLen > 0; k++) {
            int len = repeats[k];
            // For sequences of length % 3 == 0, deleting 1 character saves 1 replacement
            if (len % 3 == 0) {
                repeats[k] -= 1;
                overLen -= 1;
            }
        }
        
        for (int k = 0; k < repeatCount && overLen > 0; k++) {
            int len = repeats[k];
            // For sequences of length % 3 == 1, deleting 2 characters saves 1 replacement
            if (len % 3 == 1 && overLen >= 2) {
                repeats[k] -= 2;
                overLen -= 2;
            }
        }
        
        for (int k = 0; k < repeatCount && overLen > 0; k++) {
            // For other sequences, delete 3 characters to save 1 replacement
            while (repeats[k] >= 3 && overLen >= 3) {
                repeats[k] -= 3;
                overLen -= 3;
            }
        } // overLen < 3 ลบไปก็ไม่มีผลอะไรเพิ่มต่อการคิด replace ต่อ
        
        // Calculate remaining replacements needed
        int replace = 0;
        for (int k = 0; k < repeatCount; k++) {
            if (repeats[k] >= 3) {
                replace += repeats[k] / 3;
            }
        }   
        // ต้องลบให้เหลือ 20 แน่ๆ แต่จะลบยังไงให้ replace น้อยที่สุด
        return deleteCount + max(replace, missingTypes);
    }
}