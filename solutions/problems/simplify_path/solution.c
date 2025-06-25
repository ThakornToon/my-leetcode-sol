char* simplifyPath(char* path) {
    char** stack = (char**)malloc(strlen(path) * sizeof(char*));
    int top = -1;
    int size = strlen(path);
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) { // สตริงทั้งสองเหมือนกัน
            if (top >= 0) {
                free(stack[top]);
                top--;
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            top++;
            stack[top] = strdup(token);
        }
        token = strtok(NULL, "/"); // ทำงานต่อจากสตริงเดิมที่ถูกประมวลผลไปแล้ว
    }
    
    char* result = (char*)malloc(size + 1);
    result[0] = '/';
    result[1] = '\0';
    
    for (int i = 0; i <= top; i++) {
        strcat(result, stack[i]);
        if (i != top) {
            strcat(result, "/");
        }
        free(stack[i]);
    }
    
    free(stack);
    return result;
}