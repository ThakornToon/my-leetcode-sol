/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    
    // เริ่มต้นผลลัพธ์เป็น -1 ทั้งหมด
    for (int i = 0; i < numsSize; i++) {
        result[i] = -1;
    }
    
    // วนลูป 2 เท่าของขนาดอาร์เรย์เพื่อจัดการ circular
    for (int i = 0; i < 2 * numsSize; i++) {
        int current_idx = i % numsSize;
        
        // เปรียบเทียบกับค่าใน stack
        while (top >= 0 && nums[current_idx] > nums[stack[top]]) {
            result[stack[top--]] = nums[current_idx];
        }
        
        // เก็บ index เฉพาะรอบแรก
        if (i < numsSize) {
            stack[++top] = current_idx;
        }
    }
    
    free(stack);
    return result;
}