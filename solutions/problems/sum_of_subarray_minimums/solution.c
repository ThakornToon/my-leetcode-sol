int sumSubarrayMins(int* arr, int arrSize) {
    const int MOD = 1000000007;
    int* stack = (int*)malloc(arrSize * sizeof(int));
    int top = -1;
    
    // Arrays สำหรับเก็บขอบเขต
    int* left = (int*)malloc(arrSize * sizeof(int));
    int* right = (int*)malloc(arrSize * sizeof(int));
    
    // หาขอบเขตซ้าย (element ทางซ้ายที่น้อยกว่าอันแรก)
    for (int i = 0; i < arrSize; i++) {
        while (top >= 0 && arr[stack[top]] >= arr[i]) {
            top--;
        }
        left[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = i;
    }
    
    top = -1; // รีเซ็ต stack
    
    // หาขอบเขตขวา (element ทางขวาที่น้อยกว่าหรือเท่ากันอันแรก)
    for (int i = arrSize - 1; i >= 0; i--) {
        while (top >= 0 && arr[stack[top]] > arr[i]) {
            top--;
        }
        right[i] = (top == -1) ? arrSize : stack[top];
        stack[++top] = i;
    }
    
    // คำนวณผลรวม
    long long total = 0;
    for (int i = 0; i < arrSize; i++) {
        long long count = (long long)(i - left[i]) * (right[i] - i);
        total = (total + (count % MOD) * arr[i]) % MOD;
    }
    
    free(stack);
    free(left);
    free(right);
    
    return (int)total;
}