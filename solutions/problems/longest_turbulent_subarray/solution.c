int maxTurbulenceSize(int* arr, int arrSize) {
    int maxLen = 1;
    int currLen = 1;
    int prevSign = 0; // 0: ไม่มี, 1: ขึ้น, -1: ลง
    
    for (int i = 1; i < arrSize; i++) {
        int currSign;
        if (arr[i] > arr[i - 1]) {
            currSign = 1;
        } else if (arr[i] < arr[i - 1]) {
            currSign = -1;
        } else {
            currSign = 0;
        }
        
        if (currSign == 0) {
            // เริ่มใหม่
            currLen = 1;
        } else if (currSign == prevSign) {
            // สัญญาณไม่สลับ เริ่มใหม่
            currLen = 2;
        } else {
            // สัญญาณสลับ ขยายความยาว
            currLen++;
        }
        
        maxLen = currLen > maxLen ? currLen : maxLen;
        prevSign = currSign;
    }
    
    return maxLen;
}