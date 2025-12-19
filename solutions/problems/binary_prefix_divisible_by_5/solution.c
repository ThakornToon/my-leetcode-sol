/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool* answer = (bool*)malloc(numsSize * sizeof(bool));
    *returnSize = numsSize;
    
    int remainder = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // คำนวณ remainder ใหม่
        // (a * 2 + b) % 5 = ((a % 5) * 2 + b) % 5
        remainder = (remainder * 2 + nums[i]) % 5;
        
        // ตรวจสอบหารลงตัว
        answer[i] = (remainder == 0);
    }
    
    return answer;
}