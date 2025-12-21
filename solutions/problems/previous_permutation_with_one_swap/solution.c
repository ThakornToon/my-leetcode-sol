/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* prevPermOpt1(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int* result = (int*)malloc(arrSize * sizeof(int));
    
    // Copy
    for (int i = 0; i < arrSize; i++) {
        result[i] = arr[i];
    }
    
    // หาตำแหน่งแรกที่ arr[i] > arr[i+1] เพื่อเปลี่ยน ไล่จากทางขวา 
    // 123 -> สลับไม่ได้, 221 -> 212
    int i;
    for (i = arrSize - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            break;
        }
    }
    
    // ถ้าไม่เจอถือว่าเป้นค่าน้อยสุดแล้ว
    if (i < 0) {
        return result;
    }
    
    // มองทางขวาหาค่าน้อยกว่าที่มากที่สุดมาสลับ
    int j = i + 1;
    int maxIndex = j;
    int maxVal = arr[j];
    
    for (int k = j + 1; k < arrSize; k++) {
        if (arr[k] < arr[i] && arr[k] > maxVal) {
            maxVal = arr[k];
            maxIndex = k;
        }
    }
    
    // สลับ arr[i] กับ arr[maxIndex]
    swap(&result[i], &result[maxIndex]);
    
    return result;
}