bool checkPossibility(int* nums, int numsSize) {
    int modifications = 0;
    
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            modifications++;
            
            if (modifications > 1) {
                return false;
            }
            
            // มีสองทางเลือกเมื่อพบปัญหา:
            // 1. ลด nums[i] หรือ 2. เพิ่ม nums[i+1]
            if (i > 0 && nums[i - 1] > nums[i + 1]) {
                // กรณี: [3, 4, 2] → ต้องเพิ่ม nums[i+1] = nums[i]
                nums[i + 1] = nums[i];
            } else {
                // กรณี: [1, 4, 2] → ต้องลด nums[i] = nums[i-1] (หรือ nums[i+1])
                nums[i] = nums[i + 1];
            }
        }
    }
    
    return true;
}