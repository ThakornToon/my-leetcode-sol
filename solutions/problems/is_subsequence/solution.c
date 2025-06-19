bool isSubsequence(char* s, char* t) {
    int sp = 0;
    int tp = 0;

    while (sp < strlen(s) && tp < strlen(t)) {
        if (s[sp] == t[tp]) {
            sp++;
        }
        tp++;
    }

    return sp == strlen(s);
}