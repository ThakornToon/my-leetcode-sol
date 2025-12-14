// ฟังก์ชันเปรียบเทียบสำหรับ qsort (เรียงตามค่าสัมบูรณ์)
int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    
    // เรียงตามค่าสัมบูรณ์
    int abs1 = num1 < 0 ? -num1 : num1;
    int abs2 = num2 < 0 ? -num2 : num2;
    
    if (abs1 != abs2) {
        return abs1 - abs2;
    }
    return num1 - num2; // ถ้าค่าสัมบูรณ์เท่ากัน เรียงตามค่าเดิม
}

bool canReorderDoubled(int* arr, int arrSize) {
    if (arrSize % 2 != 0) return false;
    
    // เรียงลำดับ array ตามค่าสัมบูรณ์
    qsort(arr, arrSize, sizeof(int), compare);
    
    // สร้าง hash map แบบง่ายๆ
    int* count = (int*)calloc(200001, sizeof(int)); // สำหรับค่า -100000 ถึง 100000
    const int OFFSET = 100000;
    
    // นับความถี่
    for (int i = 0; i < arrSize; i++) {
        count[arr[i] + OFFSET]++;
    }
    
    // ตรวจสอบทีละตัวตามลำดับที่เรียงแล้ว
    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];
        int idx = num + OFFSET;
        
        if (count[idx] == 0) continue; // ใช้ไปแล้ว
        
        // หาคู่ที่เป็น 2 * num
        int target = num * 2;
        int targetIdx = target + OFFSET;
        
        // ตรวจสอบว่า target อยู่ใน range และมีเหลือ
        if (targetIdx < 0 || targetIdx > 200000 || count[targetIdx] == 0) {
            free(count);
            return false;
        }
        
        // ลดจำนวนทั้งสองตัว
        count[idx]--;
        count[targetIdx]--;
    }
    
    free(count);
    return true;
}