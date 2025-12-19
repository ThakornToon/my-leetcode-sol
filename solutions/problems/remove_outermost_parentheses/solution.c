char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int result_index = 0;
    
    int balance = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            // ถ้า balance > 0 แสดงว่าไม่ใช่ outermost '('
            if (balance > 0) {
                result[result_index++] = '(';
            }
            balance++;
        } else { // s[i] == ')'
            balance--;
            // ถ้า balance > 0 แสดงว่าไม่ใช่ outermost ')'
            if (balance > 0) {
                result[result_index++] = ')';
            }
        }
    }
    
    result[result_index] = '\0';
    return result;
}