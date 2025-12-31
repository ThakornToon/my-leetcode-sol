bool uniqueOccurrences(int* arr, int arrSize) {
    // สำหรับโจทย์นี้ arr[i] ∈ [-1000, 1000]
    // ใช้ array ขนาด 2001 เพื่อเก็บความถี่
    int freq[2001] = {0};  // index 0-2000 สำหรับค่า -1000 ถึง 1000
        
    // นับความถี่
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i] + 1000]++;  // shift index
    }
        
    // ตรวจสอบความถี่ที่ไม่ซ้ำกัน
    bool seen[1001] = {false};  // ความถี่สูงสุดได้ 1000 ครั้ง
        
    for (int i = 0; i < 2001; i++) {
        if (freq[i] > 0) {
            if (seen[freq[i]]) {
                return false;
            }
            seen[freq[i]] = true;
        }
    }
        
    return true;
}