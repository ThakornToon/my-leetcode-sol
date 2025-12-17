typedef struct {
    int val;
    int idx;
} Pair;

int compare_asc(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    if (p1->val == p2->val) return p1->idx - p2->idx;
    return p1->val - p2->val;
}

int compare_desc(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    if (p1->val == p2->val) return p1->idx - p2->idx;
    return p2->val - p1->val;
}

int oddEvenJumps(int* arr, int arrSize) {
    // สร้าง nextGreater และ nextSmaller
    int* nextHigher = (int*)malloc(arrSize * sizeof(int));
    int* nextLower = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        nextHigher[i] = -1;
        nextLower[i] = -1;
    }
    
    // หา nextHigher (สำหรับ odd jump)
    Pair* pairs = (Pair*)malloc(arrSize * sizeof(Pair));
    for (int i = 0; i < arrSize; i++) {
        pairs[i].val = arr[i];
        pairs[i].idx = i;
    }
    
    // เรียงจากน้อยไปมาก ใช้ stack หา nextHigher
    qsort(pairs, arrSize, sizeof(Pair), compare_asc);
    
    // Monotonic stack
    int* stack = (int*)malloc(arrSize * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < arrSize; i++) {
        int idx = pairs[i].idx;
        while (top >= 0 && stack[top] < idx) {
            nextHigher[stack[top--]] = idx;
        }
        stack[++top] = idx;
    }
    
    // เรียงจากมากไปน้อย ใช้ stack หา nextLower
    qsort(pairs, arrSize, sizeof(Pair), compare_desc);
    top = -1;
    
    for (int i = 0; i < arrSize; i++) {
        int idx = pairs[i].idx;
        while (top >= 0 && stack[top] < idx) {
            nextLower[stack[top--]] = idx;
        }
        stack[++top] = idx;
    }
    
    // DP จากขวาไปซ้าย
    bool* canReachOdd = (bool*)calloc(arrSize, sizeof(bool));
    bool* canReachEven = (bool*)calloc(arrSize, sizeof(bool));
    
    // Base case
    canReachOdd[arrSize-1] = true;
    canReachEven[arrSize-1] = true;
    
    int result = 1; // index สุดท้าย
    
    // วนจากขวาไปซ้าย
    for (int i = arrSize - 2; i >= 0; i--) {
        // Odd jump
        if (nextHigher[i] != -1) {
            canReachOdd[i] = canReachEven[nextHigher[i]];
        }
        
        // Even jump
        if (nextLower[i] != -1) {
            canReachEven[i] = canReachOdd[nextLower[i]];
        }
        
        // ถ้าเริ่มจาก i ด้วย odd jump (ครั้งแรก) แล้วไปถึงจุดสิ้นสุดได้
        if (canReachOdd[i]) {
            result++;
        }
    }
    
    free(nextHigher);
    free(nextLower);
    free(pairs);
    free(stack);
    free(canReachOdd);
    free(canReachEven);
    
    return result;
}