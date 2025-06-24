bool isMatch(char* s, char* p) {
    int i = 0, j = 0;
    int starIdx = -1, match = 0;
    int lenS = strlen(s), lenP = strlen(p);

    while (i < lenS) {
        // Match current character or '?'
        if (j < lenP && (p[j] == s[i] || p[j] == '?')) {
            i++;
            j++;
        }
        // Record position of '*' and match point in s
        else if (j < lenP && p[j] == '*') { // เจอ * ครั้งแรกลองไม่ใช้ก่อน บันทึกค่าไว้ย้อนมาคิดต่อ
            starIdx = j;
            match = i;
            j++;
        }
        // If mismatch but there was a previous '*', backtrack
        else if (starIdx != -1) { // ลองใช้ * หนึ่งครั้งถ้ายังไม่ได้ก็ลองสองครั้้งไปเรื่อยๆจนสุด
            j = starIdx + 1;
            match++;
            i = match;
        }
        // No match and no '*'
        else { // ลองทุกวิธีก็ยังไม่ตรง
            return false;
        }
    }

    // Check for remaining characters in p (they must all be '*')
    while (j < lenP && p[j] == '*') {
        j++;
    }

    return j == lenP;
}