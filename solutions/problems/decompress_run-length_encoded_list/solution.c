/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    // คำนวณขนาดผลลัพธ์
    int totalSize = 0;
    for (int i = 0; i < numsSize; i += 2) {
        totalSize += nums[i];  // nums[i] คือ freq
    }
    
    *returnSize = totalSize;
    int* result = (int*)malloc(totalSize * sizeof(int));
    
    // ใส่ค่าลงใน result
    int index = 0;
    for (int i = 0; i < numsSize; i += 2) {
        int freq = nums[i];
        int val = nums[i + 1];
        
        for (int j = 0; j < freq; j++) {
            result[index++] = val;
        }
    }
    
    return result;

}