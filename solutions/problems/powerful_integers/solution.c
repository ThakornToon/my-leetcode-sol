/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize) {
    if (bound < 2) {
        *returnSize = 0;
        return NULL;
    }
    
    // ใช้ hash table แบบง่าย (bound ≤ 10^6)
    int* seen = (int*)calloc(bound + 1, sizeof(int));
    int* result = (int*)malloc((bound + 1) * sizeof(int));
    int count = 0;
    
    // สร้างลิสต์ของ x^i
    int x_powers[21]; // 2^20 > 10^6
    int x_count = 0;
    if (x == 1) {
        x_powers[x_count++] = 1;
    } else {
        long long val = 1;
        while (val <= bound) {
            x_powers[x_count++] = (int)val;
            val *= x;
        }
    }
    
    // สร้างลิสต์ของ y^j
    int y_powers[21];
    int y_count = 0;
    if (y == 1) {
        y_powers[y_count++] = 1;
    } else {
        long long val = 1;
        while (val <= bound) {
            y_powers[y_count++] = (int)val;
            val *= y;
        }
    }
    
    // ทดสอบทุกคู่
    for (int i = 0; i < x_count; i++) {
        for (int j = 0; j < y_count; j++) {
            int sum = x_powers[i] + y_powers[j];
            if (sum <= bound && !seen[sum]) {
                seen[sum] = 1;
                result[count++] = sum;
            }
        }
    }
    
    // เรียงลำดับ (ใช้ insertion sort ง่ายๆ)
    for (int i = 1; i < count; i++) {
        int key = result[i];
        int j = i - 1;
        while (j >= 0 && result[j] > key) {
            result[j + 1] = result[j];
            j--;
        }
        result[j + 1] = key;
    }
    
    free(seen);
    *returnSize = count;
    return result;
}