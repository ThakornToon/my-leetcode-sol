char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // ตรวจสอบว่า str1 + str2 == str2 + str1
    char concat1[2001], concat2[2001];
    strcpy(concat1, str1);
    strcat(concat1, str2);

    strcpy(concat2, str2);
    strcat(concat2, str1);

    if (strcmp(concat1, concat2) != 0) {
        return "";  // ไม่มี common divisor
    }
    
    // Find GCD of lengths
    int a = len1, b = len2;
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    
    // Return prefix of length a
    char* result = (char*)malloc((a + 1) * sizeof(char));
    strncpy(result, str1, a);
    result[a] = '\0';
    
    return result;
}