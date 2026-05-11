/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    // คำนวณขนาดของผลลัพธ์
    int totalDigits = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num == 0) {
            totalDigits++;
        } else {
            while (num > 0) {
                totalDigits++;
                num /= 10;
            }
        }
    }
    
    int* result = (int*)malloc(totalDigits * sizeof(int));
    *returnSize = totalDigits;
    
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        
        if (num == 0) {
            result[index++] = 0;
            continue;
        }
        
        // หาจำนวนหลัก
        int temp = num;
        int digitCount = 0;
        while (temp > 0) {
            digitCount++;
            temp /= 10;
        }
        
        // เก็บหลักใน array ชั่วคราว (จะได้จากขวาไปซ้าย)
        int* digits = (int*)malloc(digitCount * sizeof(int));
        temp = num;
        for (int j = digitCount - 1; j >= 0; j--) {
            digits[j] = temp % 10;
            temp /= 10;
        }
        
        // คัดลอกไปยัง result
        for (int j = 0; j < digitCount; j++) {
            result[index++] = digits[j];
        }
        
        free(digits);
    }
    
    return result;
}