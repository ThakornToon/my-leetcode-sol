/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_STACK_SIZE 200

typedef struct {
    int id;
    int start_time;
} FunctionCall;

int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    int* result = (int*)calloc(n, sizeof(int));
    *returnSize = n;
    FunctionCall* stack = (FunctionCall*)malloc(MAX_STACK_SIZE * sizeof(FunctionCall));
    int stackPtr = -1;  // pointer ชี้ตำแหน่งบนสุดของ stack
    int prevTime = 0;
    
    for (int i = 0; i < logsSize; i++) {
        char* log = logs[i];
        char* saveptr;
        
        // Parse log ด้วย strtok_r
        char* id_str = strtok_r(log, ":", &saveptr);
        char* type = strtok_r(NULL, ":", &saveptr);
        char* time_str = strtok_r(NULL, ":", &saveptr);
        
        int id = atoi(id_str);
        int timestamp = atoi(time_str);
        
        if (strcmp(type, "start") == 0) {
            // ถ้ามี function กำลังทำงานอยู่
            if (stackPtr >= 0) {
                // บันทึกเวลาของ function ก่อนหน้า
                result[stack[stackPtr].id] += timestamp - prevTime;
            }
            
            // Push ใหม่
            stackPtr++;
            stack[stackPtr].id = id;
            stack[stackPtr].start_time = timestamp;
            prevTime = timestamp;
            
        } else { // "end"
            // บันทึกเวลาของ function ปัจจุบัน
            result[stack[stackPtr].id] += timestamp - prevTime + 1;
            
            // Pop
            stackPtr--;
            prevTime = timestamp + 1;
        }
    }
    
    free(stack);
    return result;
}