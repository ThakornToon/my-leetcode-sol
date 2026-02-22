/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
4x + 2y = T
x + y = C

x = (T - 2C) / 2
y = C - x

x ต้องเป็นจำนวนเต็ม ≥ 0
y ต้องเป็นจำนวนเต็ม ≥ 0
*/
int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize) {
    // ตรวจสอบเงื่อนไขพื้นฐาน
    // T - 2C ต้องเป็นเลขคู่ (หาร 2 ลงตัว) และ >= 0
    int diff = tomatoSlices - 2 * cheeseSlices;
    
    // ตรวจสอบว่า diff เป็นเลขคู่และ >= 0
    if (diff < 0 || diff % 2 != 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // คำนวณ x = (T - 2C) / 2
    int jumbo = diff / 2;
    int small = cheeseSlices - jumbo;
    
    // ตรวจสอบว่า small >= 0
    if (small < 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // สร้างผลลัพธ์
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = jumbo;
    result[1] = small;
    
    return result;
}