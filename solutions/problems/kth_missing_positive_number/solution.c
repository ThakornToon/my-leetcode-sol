int findKthPositive(int* arr, int arrSize, int k) {
    int missingCount = 0;
    int prev = 0;
    for (int i = 0; i < arrSize; i++) {
        // ค่าที่ควรจะเป็นที่ตำแหน่ง i คือ i+1
        int missing = arr[i] - prev - 1;
    
        if (missing >= k) {
            // k-th missing อยู่ระหว่าง expected ถึง arr[i]
            return prev + k;
        }
        
        // ปรับ k เนื่องจาก missing ตัวนี้ถูกข้ามไป
        k -= missing;
        prev = arr[i];

    }
    
    // ถ้า k ยังเหลือ แสดงว่าคำตอบอยู่หลังตัวสุดท้าย
    return prev + k;
}