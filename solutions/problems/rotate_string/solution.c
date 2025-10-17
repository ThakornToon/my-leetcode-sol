bool rotateString(char* s, char* goal) {
    if (strlen(s) != strlen(goal)) {
        return false;
    }
    
    char temp[201]; // ขนาดใหญ่พอสำหรับ s สองตัว
    strcpy(temp, s);
    strcat(temp, s);
    
    return strstr(temp, goal) != NULL; // หา goal ใน temp
}