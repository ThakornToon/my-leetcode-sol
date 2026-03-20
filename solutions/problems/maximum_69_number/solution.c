int maximum69Number (int num) {
    // แปลงตัวเลขเป็น string
    char numStr[10];
    sprintf(numStr, "%d", num);
    
    // หา '6' ตัวแรกแล้วเปลี่ยนเป็น '9'
    for (int i = 0; numStr[i] != '\0'; i++) {
        if (numStr[i] == '6') {
            numStr[i] = '9';
            break;
        }
    }
    
    // แปลงกลับเป็น int
    return atoi(numStr);
}