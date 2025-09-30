bool isPossible(int* nums, int numsSize) {
    // Count frequency of each number
    int count[2001] = {0};
    int end[2001] = {0};
    
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + 1000]++;
    }
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        
        if (count[num + 1000] == 0) continue;
        
        count[num + 1000]--;
        
        // เพิ่มในลำดับที่มีอยู่
        if (num - 1 + 1000 >= 0 && end[num - 1 + 1000] > 0) {
            end[num - 1 + 1000]--;
            end[num + 1000]++;
        }
        // ถ้าเพิ่มไม่ได้ต้องสร้างลำดับใหม่ ต้องมี num+1 และ num+2
        else if (num + 2 + 1000 <= 2000  && count[num + 1 + 1000] > 0 && count[num + 2 + 1000] > 0) {
            count[num + 1 + 1000]--;
            count[num + 2 + 1000]--;
            end[num + 2 + 1000]++;
        } else {
            return false;
        }
    }
    
    return true;
}