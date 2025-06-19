char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = 0;
    
    for (int i = 0; i < len; i++) {
        while (k > 0 && top > 0 && stack[top-1] > num[i]) {
            top--;
            k--;
        }
        stack[top++] = num[i];
    }
    
    // ลบตัวเลขที่เหลือถ้า k > 0
    top -= k;
    stack[top] = '\0';
    
    // ลบ 0 นำหน้า
    int start = 0;
    while (stack[start] == '0') {
        start++;
    }
    
    if (start == top) {
        return "0";
    }
    
    char* result = (char*)malloc((top - start + 1) * sizeof(char));
    strcpy(result, stack + start);
    free(stack);
    
    return result;
}