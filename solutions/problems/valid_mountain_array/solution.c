

bool validMountainArray(int* arr, int arrSize){
    int i = 0;
    
    // เดินขึ้นไปจนถึงยอดเขา
    while (i + 1 < arrSize && arr[i] < arr[i + 1]) {
        i++;
    }
    
    // ตรวจสอบว่า i อยู่ที่จุดเริ่มต้นหรือจุดสิ้นสุดหรือไม่
    if (i == 0 || i == arrSize - 1) {
        return false;
    }
    
    // เดินลงจากยอดเขา
    while (i + 1 < arrSize && arr[i] > arr[i + 1]) {
        i++;
    }
    
    // ตรวจสอบว่าเดินถึงจุดสิ้นสุดแล้วหรือไม่
    return i == arrSize - 1;
}