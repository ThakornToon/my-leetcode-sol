int findSpecialInteger(int* arr, int arrSize) {
    int targetCount = arrSize / 4;  // จำนวนที่ต้องเกิน 25%
    int count = 1;
    
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
            if (count > targetCount) {
                return arr[i];
            }
        } else {
            count = 1;
        }
    }
    
    // ถ้าไม่เจอระหว่างทาง (เช่น กรณี array ยาว 1)
    return arr[0];
}