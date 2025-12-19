char* baseNeg2(int n) {
    if (n == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    
    // สูงสุดประมาณ 32 bits + null terminator
    char* result = (char*)malloc(33 * sizeof(char));
    int index = 32;
    result[index] = '\0';
    
    while (n != 0) {
        int remainder = n % (-2);
        n = n / (-2);
        
        // ปรับ remainder ให้เป็น 0 หรือ 1
        if (remainder < 0) {
            remainder += 2;
            n += 1;
        }
        
        // เก็บจากขวาไปซ้าย (index ลดลง)
        index--;
        result[index] = remainder + '0';
    }
    
    // คืน pointer ไปยังส่วนที่ใช้งาน
    char* final_result = strdup(&result[index]);
    free(result);
    
    return final_result;
}