bool isGood(int* nums, int numsSize) {
    // ค้นหาค่าสูงสุดใน array
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    // ตรวจสอบเงื่อนไขพื้นฐาน: ค่าสูงสุดต้อง = numsSize - 1
    if (max != numsSize - 1) {
        return false;
    }
    
    // สร้าง frequency array (ขนาด max+1)
    int* freq = (int*)calloc(max + 1, sizeof(int));
    
    // นับความถี่
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }
    
    // ตรวจสอบ: 1 ถึง max-1 ต้องมี frequency = 1
    for (int i = 1; i < max; i++) {
        if (freq[i] != 1) {
            free(freq);
            return false;
        }
    }
    
    // ตรวจสอบ: max ต้องมี frequency = 2
    bool result = (freq[max] == 2);
    
    free(freq);
    return result;
}