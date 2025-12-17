/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int maxSize = numSize + 10; // 10 เพราะ k อาจมี digit มากกว่า num
    int* result = (int*)malloc(maxSize * sizeof(int));
    
    int carry = 0;
    int i = numSize - 1; // เริ่มจากหลักหน่วย (ท้าย array)
    int pos = maxSize - 1; // ใส่ผลลัพธ์จากท้ายไปหน้า
    
    // บวกจนกว่าจะครบทุกหลักหรือ k = 0
    while (i >= 0 || k > 0 || carry > 0) {
        int sum = carry;
        
        if (i >= 0) {
            sum += num[i];
            i--;
        }
        
        if (k > 0) {
            sum += k % 10;
            k /= 10;
        }
        
        result[pos] = sum % 10;
        carry = sum / 10;
        pos--;
    }
    
    // คำนวณขนาดผลลัพธ์
    *returnSize = maxSize - pos - 1;
    
    // คัดลอกผลลัพธ์ไปยัง array ที่มีขนาดพอดี
    int* finalResult = (int*)malloc(*returnSize * sizeof(int));
    for (int j = 0; j < *returnSize; j++) {
        finalResult[j] = result[pos + 1 + j];
    }
    
    free(result);
    return finalResult;
}