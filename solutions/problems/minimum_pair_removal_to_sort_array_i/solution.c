// ฟังก์ชันตรวจสอบว่า array เป็น non-decreasing หรือไม่
int is_non_decreasing(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0; // false
        }
    }
    return 1; // true
}

// ฟังก์ชันหาคู่ที่ sum ต่ำสุด (ซ้ายสุดถ้าเท่ากัน)
void find_min_pair(int* nums, int size, int* min_sum, int* min_index) {
    *min_sum = INT_MAX;
    *min_index = -1;
    
    for (int i = 0; i < size - 1; i++) {
        int current_sum = nums[i] + nums[i + 1];
        if (current_sum < *min_sum) {
            *min_sum = current_sum;
            *min_index = i;
        }
    }
}

// ฟังก์ชันลบ element จาก array
void remove_element(int* arr, int size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}
int minimumPairRemoval(int* nums, int numsSize) {
    if (is_non_decreasing(nums, numsSize)) return 0;
    
    // สร้าง array สำรองเพื่อไม่แก้ไข original
    int* arr = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        arr[i] = nums[i];
    }
    
    int size = numsSize;
    int operations = 0;
    
    // Simulation loop
    while (1) {
        // หาคู่ที่ sum ต่ำสุด
        int min_sum, min_index;
        find_min_pair(arr, size, &min_sum, &min_index);
        
        // Merge คู่นั้น
        arr[min_index] = min_sum; // แทนที่ตัวซ้ายด้วย sum
        
        // ลบตัวขวาออก
        remove_element(arr, size, min_index + 1);
        size--; // ลดขนาด array
        
        operations++;
        
        // ตรวจสอบว่า non-decreasing แล้วหรือยัง
        if (is_non_decreasing(arr, size)) {
            break;
        }
    }
    
    free(arr);
    return operations;
}