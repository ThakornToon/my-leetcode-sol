int max(int a, int b) {
    return a > b ? a : b;
}

int maximumSum(int* arr, int arrSize) {
    int dp0 = arr[0];  // ไม่เคยลบ
    int dp1 = 0;       // ลบไปแล้ว 1 ตัว
    int result = arr[0];
    
    for (int i = 1; i < arrSize; i++) {
        // สถานะ: ลบแล้ว 1 ตัว
        // ตัวเลือก 1: ลบตัวปัจจุบัน (ใช้ dp0 ก่อนหน้า)
        // ตัวเลือก 2: ไม่ลบตัวปัจจุบัน (ใช้ dp1 ก่อนหน้า + arr[i])
        int new_dp1 = max(dp0, dp1 + arr[i]);
        
        // สถานะ: ไม่เคยลบ (Kadane ปกติ)
        int new_dp0 = max(arr[i], dp0 + arr[i]);
        
        dp0 = new_dp0;
        dp1 = new_dp1;
        
        result = max(result, max(dp0, dp1));
    }
    
    return result;
}