

char * defangIPaddr(char * address){
    int len = strlen(address);
    // ทุกจุดใช้ 3 ตัวอักษรแทน (ปกติ 1 ตัว) → เพิ่ม 2 ตัวต่อจุด
    // มี 3 จุด → เพิ่ม 6 ตัว + 1 สำหรับ null terminator
    char* result = (char*)malloc(len + 7); // len + 2*3 + 1
    
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (address[i] == '.') {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        } else {
            result[j++] = address[i];
        }
    }
    result[j] = '\0';
    
    return result;
}