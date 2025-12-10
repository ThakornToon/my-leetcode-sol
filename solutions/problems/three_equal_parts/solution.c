/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* threeEqualParts(int* arr, int arrSize, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;
    *returnSize = 2;
    
    // นับจำนวน 1 ทั้งหมด
    int totalOnes = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 1) totalOnes++;
    }
    
    // ถ้าไม่มี 1 เลย ทั้งสามส่วนเป็น 0 ได้หมด
    if (totalOnes == 0) {
        result[0] = 0;
        result[1] = arrSize - 1;
        return result;
    }
    
    // จำนวน 1 ต้องหารด้วย 3 ลงตัว
    if (totalOnes % 3 != 0) {
        return result;
    }
    
    int onesPerPart = totalOnes / 3;
    
    // หาตำแหน่งของ 1 ตัวแรกในแต่ละส่วน
    int firstOne1 = -1, firstOne2 = -1, firstOne3 = -1;
    int count = 0;
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 1) {
            count++;
            if (count == 1) firstOne1 = i;
            else if (count == onesPerPart + 1) firstOne2 = i;
            else if (count == 2 * onesPerPart + 1) {
                firstOne3 = i;
                break;
            }
        }
    }
    
    // ตรวจสอบส่วนที่เหลือหลังจาก firstOne3
    int len = arrSize - firstOne3;
    
    // ตรวจสอบว่าแต่ละส่วนมีค่าเท่ากัน
    for (int i = 0; i < len; i++) {
        if (firstOne1 + i >= arrSize || firstOne2 + i >= arrSize || firstOne3 + i >= arrSize) {
            result[0] = -1;
            result[1] = -1;
            return result;
        }
        
        if (arr[firstOne1 + i] != arr[firstOne2 + i] || 
            arr[firstOne2 + i] != arr[firstOne3 + i]) {
            result[0] = -1;
            result[1] = -1;
            return result;
        }
    }
    
    result[0] = firstOne1 + len - 1;
    result[1] = firstOne2 + len;
    
    return result;
}