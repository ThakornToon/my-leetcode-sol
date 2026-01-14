/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    
    // ใช้ deque เก็บ index (implement ด้วย array)
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int front = 0, back = -1;  // front และ back ของ deque
    
    for (int i = 0; i < numsSize; i++) {
        // 1. ลบ index ที่อยู่นอกหน้าต่างจากด้านหน้า
        if (front <= back && deque[front] < i - k + 1) {
            front++;
        }
        
        // 2. ลบ elements จากด้านหลังที่น้อยกว่า nums[i]
        while (front <= back && nums[deque[back]] <= nums[i]) {
            back--;
        }
        
        // 3. เพิ่ม index ปัจจุบัน
        deque[++back] = i;
        
        // 4. บันทึกค่าสูงสุดเมื่อผ่านหน้าต่างแรกแล้ว
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
        }
    }
    
    free(deque);
    return result;
}