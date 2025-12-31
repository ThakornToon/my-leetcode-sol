void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char* reverseParentheses(char* s) {
    int n = strlen(s);
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    
    // ทำ reverse ใน string เดิม
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;  // เก็บตำแหน่ง '('
        } else if (s[i] == ')') {
            int start = stack[top--];  // ดึงตำแหน่ง '(' ที่ตรงกัน
            reverse(s, start + 1, i - 1);  // reverse substring
        }
    }
    
    // ลบวงเล็บออก
    char* result = (char*)malloc(n + 1);
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] != '(' && s[i] != ')') {
            result[idx++] = s[i];
        }
    }
    result[idx] = '\0';
    
    free(stack);
    return result;
}