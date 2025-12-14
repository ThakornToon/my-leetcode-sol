/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define PRISON_SIZE 8

int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize) {
    *returnSize = PRISON_SIZE;
    int* result = (int*)malloc(PRISON_SIZE * sizeof(int));
    
    if (n == 0) {
        memcpy(result, cells, PRISON_SIZE * sizeof(int));
        return result;
    }
    
    // สำเนา cells ต้นฉบับ
    int current[PRISON_SIZE];
    memcpy(current, cells, PRISON_SIZE * sizeof(int));
    
    // ใช้ N % 14 เพราะ cycle length = 14
    // ถ้า N % 14 == 0 ใช้ 14 แทน (เพราะต้องการวันที่ 14 ของ cycle)
    int days = n % 14;
    if (days == 0) days = 14;
    
    // Simulate ตามจำนวนวันที่ต้องการ
    for (int day = 0; day < days; day++) {
        int next[PRISON_SIZE] = {0};
        
        // ตำแหน่งที่ 0 และ 7 เป็น 0 เสมอ
        for (int i = 1; i < PRISON_SIZE - 1; i++) {
            if (current[i-1] == current[i+1]) {
                next[i] = 1;
            } else {
                next[i] = 0;
            }
        }
        
        memcpy(current, next, PRISON_SIZE * sizeof(int));
    }
    
    memcpy(result, current, PRISON_SIZE * sizeof(int));
    return result;
}