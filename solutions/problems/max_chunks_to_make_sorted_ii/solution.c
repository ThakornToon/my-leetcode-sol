int maxChunksToSorted(int* arr, int arrSize) {
    // สร้าง suffix min array
    int suffix_min[arrSize];
    suffix_min[arrSize-1] = arr[arrSize-1];
    for (int i = arrSize-2; i >= 0; i--) {
        suffix_min[i] = (arr[i] < suffix_min[i+1]) ? arr[i] : suffix_min[i+1];
    }
    
    int chunks = 1;
    int prefix_max = arr[0];
    
    for (int i = 0; i < arrSize-1; i++) {
        if (arr[i] > prefix_max) {
            prefix_max = arr[i];
        }
        
        // ตรวจสอบว่าแบ่ง chunk ได้ไหม
        if (prefix_max <= suffix_min[i+1]) {
            chunks++;
        }
    }
    
    return chunks;
}