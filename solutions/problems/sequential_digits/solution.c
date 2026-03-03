/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize) {
    int* result = (int*)malloc(36 * sizeof(int));
    *returnSize = 0;
    
    // queue สำหรับ BFS (ใช้ array จำลอง)
    int queue[100];
    int front = 0, rear = 0;
    
    // ใส่ตัวเลข 1-9 เข้า queue
    for (int i = 1; i <= 9; i++) {
        queue[rear++] = i;
    }
    
    while (front < rear) {
        int num = queue[front++];
        
        // ถ้า num อยู่ในช่วงที่ต้องการ
        if (num >= low && num <= high) {
            result[(*returnSize)++] = num;
        }
        
        // ถ้า num มากกว่า high แล้ว ไม่ต้องต่อ
        if (num > high) continue;
        
        // หาตัวเลขสุดท้ายของ num
        int lastDigit = num % 10;
        
        // ถ้ายังต่อได้ (lastDigit < 9)
        if (lastDigit < 9) {
            int nextNum = num * 10 + (lastDigit + 1);
            if (nextNum <= high) {
                queue[rear++] = nextNum;
            }
        }
    }
    
    return result;
}