/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* answer = (int*)malloc(queriesSize * sizeof(int));
    
    // คำนวณ sum ของเลขคู่ตั้งต้น
    int evenSum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            evenSum += nums[i];
        }
    }
    
    // ประมวลผลแต่ละ query
    for (int i = 0; i < queriesSize; i++) {
        int val = queries[i][0];
        int index = queries[i][1];
        
        // ลบค่าเดิมออกจาก evenSum ถ้าเป็นเลขคู่
        if (nums[index] % 2 == 0) {
            evenSum -= nums[index];
        }
        
        // อัพเดตค่าใน nums
        nums[index] += val;
        
        // เพิ่มค่าใหม่เข้า evenSum ถ้าเป็นเลขคู่
        if (nums[index] % 2 == 0) {
            evenSum += nums[index];
        }
        
        answer[i] = evenSum;
    }
    
    return answer;
}