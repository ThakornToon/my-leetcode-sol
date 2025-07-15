char* convertToBase7(int num) {
    if (num == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }
    
    int is_negative = num < 0;
    num = abs(num);
    
    char buffer[32];
    int index = 0;
    
    while (num > 0) {
        buffer[index++] = (num % 7) + '0';
        num /= 7;
    }
    
    if (is_negative) {
        buffer[index++] = '-';
    }
    
    // Reverse the string
    char* result = (char*)malloc((index + 1) * sizeof(char));
    for (int i = 0; i < index; i++) {
        result[i] = buffer[index - 1 - i];
    }
    result[index] = '\0';
    
    return result;
}