int calPoints(char** operations, int operationsSize) {
    int* stack = (int*)malloc(operationsSize * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < operationsSize; i++) {
        char* op = operations[i];
        
        if (strcmp(op, "+") == 0) {
            // บวกสองคะแนนล่าสุด
            int score1 = stack[top];
            int score2 = stack[top - 1];
            stack[++top] = score1 + score2;
        }
        else if (strcmp(op, "D") == 0) {
            // คูณสองคะแนนล่าสุด
            int d = stack[top];
            stack[++top] = d * 2;
        }
        else if (strcmp(op, "C") == 0) {
            // ลบคะแนนล่าสุด
            top--;
        }
        else {
            // จำนวนเต็ม
            stack[++top] = atoi(op);
        }
    }
    
    // คำนวณผลรวม
    int sum = 0;
    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }
    
    free(stack);
    return sum;
}