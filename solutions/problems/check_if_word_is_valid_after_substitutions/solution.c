bool isValid(char* s) {
    int n = strlen(s);
    if (n % 3 != 0) return false;
    
    // ใช้ s เองเป็น stack
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        s[++top] = s[i];
        
        if (s[i] == 'c') {
            if (top >= 2 && s[top-1] == 'b' && s[top-2] == 'a') {
                top -= 3;
            } else {
                return false;
            }
        }
    }
    
    return top == -1;
}