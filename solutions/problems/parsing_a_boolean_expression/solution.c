bool parseBoolExpr(char* expression) {
    int n = strlen(expression);
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        char c = expression[i];
        
        if (c == ',') continue;
        
        if (c == ')') {
            // นับจำนวน operand
            int count = 0;
            char operands[10000]; // ใช้ array เก็บ operand
            
            // ดึง operand จนเจอ '('
            while (top >= 0 && stack[top] != '(') {
                char val = stack[top];
                if (val == 't' || val == 'f') {
                    operands[count++] = val;
                }
                top--;
            }
            top--; // ลบ '('
            
            // ดึง operator
            char op = stack[top];
            top--;
            
            // ประเมินผล
            bool result;
            if (op == '!') {
                result = (operands[0] == 'f'); // NOT
            } else if (op == '&') {
                result = true;
                for (int j = 0; j < count; j++) {
                    if (operands[j] == 'f') {
                        result = false;
                        break;
                    }
                }
            } else if (op == '|') {
                result = false;
                for (int j = 0; j < count; j++) {
                    if (operands[j] == 't') {
                        result = true;
                        break;
                    }
                }
            }
            
            // เก็บผลลัพธ์กลับ
            stack[++top] = result ? 't' : 'f';
        } else {
            stack[++top] = c;
        }
    }
    
    bool finalResult = stack[top] == 't';
    free(stack);
    return finalResult;
}