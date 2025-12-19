bool canThreePartsEqualSum(int* arr, int arrSize) {
    // 1. คำนวณผลรวมทั้งหมด
    int total = 0;
    for (int i = 0; i < arrSize; i++) {
        total += arr[i];
    }
    
    // 2. ตรวจสอบว่าหารด้วย 3 ลงตัวไหม
    if (total % 3 != 0) {
        return false;
    }
    
    int target = total / 3;
    int currentSum = 0;
    int count = 0;
    
    // 3. หาจำนวนส่วนที่ผลรวม = target
    for (int i = 0; i < arrSize; i++) {
        currentSum += arr[i];
        if (currentSum == target) {
            count++;
            currentSum = 0; // reset สำหรับส่วนถัดไป
        }
    }
    
    // ต้องเจออย่างน้อย 3 ส่วน (หรือมากกว่า ถ้ามีส่วนที่ sum = 0)
    return count >= 3;
}