int calculate(char* s) {
    int* stack = (int*)malloc(strlen(s) * sizeof(int));
    int top = -1;
    int result = 0;
    int current = 0;
    int sign = 1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (isdigit(ch)) {
            current = current * 10 + (ch - '0');
        } else if (ch == '+') {
            result += sign * current;
            current = 0;
            sign = 1;
        } else if (ch == '-') {
            result += sign * current;
            current = 0;
            sign = -1;
        } else if (ch == '(') {
            stack[++top] = result;
            stack[++top] = sign;
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            result += sign * current;
            current = 0;
            int prev_sign = stack[top--];
            int prev_result = stack[top--];
            result *= prev_sign;
            result += prev_result;
        }
    }
    
    free(stack);
    return result + sign * current;
}