typedef struct {
    char* str;
    int num;
} StringIntPair;

char* decodeString(char* s) {
    StringIntPair* stack = malloc(30 * sizeof(StringIntPair));
    int stack_size = 0;
    int next_num = 0;
    int buffer_size = strlen(s) * 500;
    char* curr_str = malloc(buffer_size * sizeof(char));
    curr_str[0] = '\0';
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '[') {
            stack[stack_size].str = strdup(curr_str);
            stack[stack_size].num = next_num;
            stack_size++;
            curr_str[0] = '\0';
            next_num = 0;
        } else if (s[i] == ']') {
            char* prev_str = stack[stack_size-1].str;
            int curr_num = stack[stack_size-1].num;
            stack_size--;
            
            char* temp = strdup(curr_str);
            for (int j = 1; j < curr_num; j++) {
                strcat(curr_str, temp);
            }
            char* new_str = malloc(buffer_size);
            strcpy(new_str, prev_str);
            strcat(new_str, curr_str);
            free(curr_str);
            free(prev_str);
            free(temp);
            curr_str = new_str;
        } else if (isdigit(s[i])) {
            next_num = next_num * 10 + (s[i] - '0');
        } else {
            int len = strlen(curr_str);
            curr_str[len] = s[i];
            curr_str[len+1] = '\0';
        }
    }
    
    for (int i = 0; i < stack_size; i++) {
        free(stack[i].str);
    }
    free(stack);
    return curr_str;
}