char* intToRoman(int num) {
    char* s = (char*)malloc(20 * sizeof(char)); 
    int i = 0;
    while (num >= 1000) {
        s[i++] = 'M';
        num -= 1000;
    }
    if (num >= 900) {
        s[i++] = 'C';
        s[i++] = 'M';
        num -= 900;
    }
    while (num >= 500) {
        s[i++] = 'D';
        num -= 500;
    }
    if (num >= 400) {
        s[i++] = 'C';
        s[i++] = 'D';
        num -= 400;
    }
    while (num >= 100) {
        s[i++] = 'C';
        num -= 100;
    }
    if (num >= 90) {
        s[i++] = 'X';
        s[i++] = 'C';
        num -= 90;
    }
    while (num >= 50) {
        s[i++] = 'L';
        num -= 50;
    }
    if (num >= 40) {
        s[i++] = 'X';
        s[i++] = 'L';
        num -= 40;
    }
    while (num >= 10) {
        s[i++] = 'X';
        num -= 10;
    }
    if (num >= 9) {
        s[i++] = 'I';
        s[i++] = 'X';
        num -= 9;
    }
    while (num >= 5) {
        s[i++] = 'V';
        num -= 5;
    }
    if (num >= 4) {
        s[i++] = 'I';
        s[i++] = 'V';
        num -= 4;
    }
    while (num >= 1) {
        s[i++] = 'I';
        num -= 1;
    }
    s[i] = '\0';
    return s;
}