/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// x XOR x = 0 (ตัวเลขเดียวกัน XOR กันได้ 0)
// x XOR 0 = x (XOR กับ 0 ได้ตัวเดิม)
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    
    // สร้าง prefix XOR array
    int* prefix = (int*)malloc((arrSize + 1) * sizeof(int));
    prefix[0] = 0;
    
    for (int i = 0; i < arrSize; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    
    // คำนวณผลลัพธ์สำหรับแต่ละ query
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        
        // XOR ของช่วง [left, right] = prefix[right+1] ^ prefix[left]
        result[i] = prefix[right + 1] ^ prefix[left];
    }
    
    free(prefix);
    return result;
}