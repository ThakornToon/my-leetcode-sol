bool isPerfectSquare(int n) {
    int root = (int)sqrt(n);
    return root * root == n;
}

void backtrack(int* nums, int numsSize, int* used, int* current, int pos, int* count) {
    if (pos == numsSize) {
        (*count)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        // ตรวจสอบว่าใช้ตัวเลขนี้แล้วหรือยัง
        if (used[i]) continue;
        
        // ตรวจสอบ duplicate: ถ้าตัวเลขตัวก่อนหน้าเหมือนกันและยังไม่ได้ใช้
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        
        // ตรวจสอบว่าเป็น squareful หรือไม่ (เมื่อมี element ก่อนหน้า)
        if (pos > 0 && !isPerfectSquare(current[pos-1] + nums[i])) {
            continue;
        }
        
        used[i] = 1;
        current[pos] = nums[i];
        backtrack(nums, numsSize, used, current, pos + 1, count);
        used[i] = 0;
    }
}

int numSquarefulPerms(int* nums, int numsSize) {
    // เรียงลำดับเพื่อจัดการ duplicates
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    
    int* used = (int*)calloc(numsSize, sizeof(int));
    int* current = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    
    backtrack(nums, numsSize, used, current, 0, &count);
    
    free(used);
    free(current);
    
    return count;
}