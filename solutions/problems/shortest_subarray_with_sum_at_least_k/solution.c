int shortestSubarray(int* nums, int numsSize, int k) {
    // สร้าง prefix sum array
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefix[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    // สร้าง deque (เก็บ index ที่พิจารณา)
    int* deque = (int*)malloc((numsSize + 2) * sizeof(int));
    int front = 0, back = 0;
    
    int minLength = INT_MAX;
    
    for (int i = 0; i <= numsSize; i++) {
        // ลบจากด้านหน้าและตรวจสอบคำตอบ
        while (front < back && prefix[i] - prefix[deque[front]] >= k) {
            int length = i - deque[front];
            if (length < minLength) {
                minLength = length;
            }
            front++;
        }

        // ลบ index ที่ทำให้ prefix[current] <= prefix[back] (prefix มีค่าลดลงจะไม่พิจารณา)
        while (front < back && prefix[i] <= prefix[deque[back - 1]]) {
            back--;
        } 
        
        // เพิ่ม current index
        deque[back++] = i;
    }
    
    free(prefix);
    free(deque);
    
    return minLength == INT_MAX ? -1 : minLength;
}