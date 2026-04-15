// ฟังก์ชันเปรียบเทียบสำหรับ qsort
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// Binary search function
int binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }    }
    return -1;
}

bool checkIfExist(int* arr, int arrSize) {
    // เรียงลำดับ array
    qsort(arr, arrSize, sizeof(int), compare);
    
    for (int i = 0; i < arrSize; i++) {
        int target = arr[i] * 2;
        
        // ค้นหา target ใน array (ข้าม index i)
        int j = binarySearch(arr, 0, arrSize - 1, target);
        
        if (j != -1 && j != i) {
            return true;
        }
        
        // กรณีมีค่าซ้ำ (เช่น 0,0)
        if (j != -1 && j + 1 < arrSize && arr[j + 1] == target) {
            return true;
        }
    }
    
    return false;
}