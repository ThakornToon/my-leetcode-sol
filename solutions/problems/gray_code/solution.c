/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    *returnSize = (int)pow(2, n);
    int* result = (int*)malloc(*returnSize * sizeof(int));
    result[0] = 0;
    
    for (int i = 0; i < n; i++) {
        int current_size = 1 << i; // ตำแหน่งที่จะมาลงต่อ
        int add = 1 << i; // จะเพิ่มบิต 1 ทีละตำแหน่งจากของเดิมในลักษณะย้อนกลับ
        
        for (int j = 0; j < current_size; j++) {
            result[current_size + j] = result[current_size - 1 - j] + add;
        }
    }
    
    return result;
}