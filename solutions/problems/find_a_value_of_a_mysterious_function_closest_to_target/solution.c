#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

int closestToTarget(int* arr, int arrSize, int target) {
    int curr[32];
    int next[32];
    int currSize = 0;
    
    int minDiff = ABS(arr[0] - target);
    
    for (int i = 0; i < arrSize; i++) {
        int nextSize = 0;
        
        // เพิ่ม arr[i] เข้าไป
        next[nextSize++] = arr[i];
        
        // AND กับค่าที่มีอยู่เดิม (prune duplicates)
        for (int j = 0; j < currSize; j++) {
            int newVal = curr[j] & arr[i];
            // ข้ามค่าซ้ำ
            if (newVal == next[nextSize - 1]) {
                continue;
            }
            next[nextSize++] = newVal;
        }
        
        // สลับ curr และ next
        currSize = nextSize;
        for (int j = 0; j < currSize; j++) {
            curr[j] = next[j];
        }
        
        // หาค่า diff ที่น้อยที่สุด
        for (int j = 0; j < currSize; j++) {
            int diff = curr[j] - target;
            if (diff < 0) diff = -diff;
            if (diff < minDiff) {
                minDiff = diff;
                if (minDiff == 0) return 0;
            }
        }
    }
    
    return minDiff;
}