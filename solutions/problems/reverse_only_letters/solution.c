bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char* reverseOnlyLetters(char* s) {
    int n = strlen(s);
    if (n <= 1) return s;
    
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        // หาตำแหน่งตัวอักษรจากซ้าย
        while (left < right && !isLetter(s[left])) {
            left++;
        }
        
        // หาตำแหน่งตัวอักษรจากขวา
        while (left < right && !isLetter(s[right])) {
            right--;
        }
        
        // สลับตัวอักษร
        if (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    
    return s;
}