char* convertToTitle(int columnNumber) {
    char* s = (char*)malloc(8);
    int i = 0;
    while (columnNumber > 0) { // BYC -> เหมือนการแปลงเลขฐานสิบกับยี่สิบหก 3+(26*25)+(26*26*2)
        columnNumber--; // ลดค่าเพื่อให้ A=0, B=1, ..., Z=25
        s[i++] = 'A' + (columnNumber % 26);
        columnNumber /= 26;
    }
    s[i] = '\0';
    //กลับสตริง
    i-=1;
    for (int start = 0; start < i; start++, i--) {
        char temp = s[i];
        s[i] = s[start];
        s[start] = temp;
    }
    return s;
}