/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numsSameConsecDiff(int n, int k, int* returnSize) {
    // จำนวนสูงสุดของผลลัพธ์ (9 * 2^(n-1) แต่จริงๆ น้อยกว่านี้)
    int max_size = 9 * (int)pow(2, n-1);
    int* result = (int*)malloc(max_size * sizeof(int));
    int count = 0;
    
    // ใช้ DFS แบบ recursion
    void dfs(int current, int length) {
        if (length == n) {
            result[count++] = current;
            return;
        }
        
        int last_digit = current % 10;
        
        // ถ้า k = 0 มีเพียงตัวเลือกเดียว
        if (k == 0) {
            dfs(current * 10 + last_digit, length + 1);
            return;
        }
        
        // ตัวเลือก 1: last_digit + k
        int next_digit = last_digit + k;
        if (next_digit <= 9) {
            dfs(current * 10 + next_digit, length + 1);
        }
        
        // ตัวเลือก 2: last_digit - k
        next_digit = last_digit - k;
        if (next_digit >= 0) {
            dfs(current * 10 + next_digit, length + 1);
        }
    }
    
    // เริ่มจากหลักแรก (1-9)
    for (int first_digit = 1; first_digit <= 9; first_digit++) {
        dfs(first_digit, 1);
    }
    
    *returnSize = count;
    return result;
}