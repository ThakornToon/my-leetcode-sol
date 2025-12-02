int longestMountain(int* arr, int arrSize) {
    if (arrSize < 3) return 0;
    
    int maxLen = 0;
    int i = 0;
    
    while (i < arrSize - 1) {
        // Phase 1: ข้ามค่าที่ไม่เพิ่มขึ้น
        while (i < arrSize - 1 && arr[i] >= arr[i+1]) {
            i++;
        }
        
        int start = i;  // จุดเริ่มต้นของภูเขา
        
        // Phase 2: เพิ่มขึ้น
        while (i < arrSize - 1 && arr[i] < arr[i+1]) {
            i++;
        }
        
        if (i == start) continue;  // ไม่มีการเพิ่มขึ้น
        
        int peak = i;  // จุดสูงสุด
        
        // Phase 3: ลดลง
        while (i < arrSize - 1 && arr[i] > arr[i+1]) {
            i++;
        }
        
        if (i > peak) {  // มีการลดลงจริง
            int len = i - start + 1;
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }
    
    return maxLen;
}