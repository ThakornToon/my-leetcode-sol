char* removeDuplicates(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        if (top >= 0 && stack[top] == s[i]) {
            // Remove duplicate
            top--;
        } else {
            // Push to stack
            stack[++top] = s[i];
        }
    }
    
    stack[top + 1] = '\0';
    
    char* result = (char*)malloc((top + 2) * sizeof(char));
    strcpy(result, stack);
    free(stack);
    
    return result;
}