/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int evenIndex = 0;  // ตำแหน่งสำหรับเลขคู่ (index คู่)
    int oddIndex = 1;   // ตำแหน่งสำหรับเลขคี่ (index คี่)
    
    while (evenIndex < numsSize && oddIndex < numsSize) {
        // หาตำแหน่งที่เลขคู่อยู่ในตำแหน่งคี่
        while (evenIndex < numsSize && nums[evenIndex] % 2 == 0) {
            evenIndex += 2;
        }
        
        // หาตำแหน่งที่เลขคี่อยู่ในตำแหน่งคู่
        while (oddIndex < numsSize && nums[oddIndex] % 2 == 1) {
            oddIndex += 2;
        }
        
        // ถ้ายังไม่จบ array ให้สลับ
        if (evenIndex < numsSize && oddIndex < numsSize) {
            swap(&nums[evenIndex], &nums[oddIndex]);
        }
    }
    
    *returnSize = numsSize;
    return nums;
}