/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ฟังก์ชันนับจำนวนบิต 1 (popcount)
int countBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// ฟังก์ชันเปรียบเทียบสำหรับ qsort
int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    
    int bits1 = countBits(num1);
    int bits2 = countBits(num2);
    
    if (bits1 != bits2) {
        return bits1 - bits2;  // เรียงตามจำนวนบิต 1
    } else {
        return num1 - num2;    // ถ้าเท่ากัน เรียงตามค่า
    }
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    // copy array (เพราะเราต้อง return array ใหม่)
    int* result = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        result[i] = arr[i];
    }
    
    // เรียงลำดับ
    qsort(result, arrSize, sizeof(int), compare);
    
    *returnSize = arrSize;
    return result;
}