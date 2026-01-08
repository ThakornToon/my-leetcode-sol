#define MAX_NUM 100001

int maxEqualFreq(int* nums, int numsSize) {
    int count[MAX_NUM] = {0}; // ความถี่ของตัวเลขแต่ละตัว
    int freqCount[MAX_NUM] = {0}; // ความถี่ปรากฎกี่ครั้ง
    int maxFreq = 0;
    int result = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int currentFreq = count[num];
        
        // ลดความถี่ของความถี่เก่าออก
        if (currentFreq > 0) {
            freqCount[currentFreq]--;
        }
        
        // เพิ่มความถี่ใหม่
        count[num]++;
        currentFreq = count[num];
        freqCount[currentFreq]++;
        
        // อัปเดตความถี่สูงสุด
        if (currentFreq > maxFreq) {
            maxFreq = currentFreq;
        }
        
        // ตรวจสอบเงื่อนไขที่ถูกต้อง
        int isValid = 0;
        
        // กรณี 1: ความถี่ทั้งหมดเป็น 1
        if (maxFreq == 1) {
            isValid = 1;
        }
        // กรณี 2: มีความถี่ที่แตกต่างกันสองค่า โดยหนึ่งในนั้นมากกว่าอีกค่าหนึ่งอยู่ 1
        else if (freqCount[maxFreq] == 1 && 
                freqCount[maxFreq] * maxFreq + freqCount[maxFreq - 1] * (maxFreq - 1) == i + 1) { // ตรวจสอบจำนวนข้อมูลทั้งหมด
            isValid = 1;
        }
        // กรณี 3: มีความถี่ 1 ปรากฏเพียงครั้งเดียว
        else if (freqCount[1] == 1 && 
                freqCount[1] * 1 + freqCount[maxFreq] * maxFreq == i + 1) { // ตรวจสอบจำนวนข้อมูลทั้งหมด
            isValid = 1;
        }
        
        // บันทึกผลลัพธ์หากเงื่อนไขถูกต้อง
        if (isValid) {
            result = i + 1; // ความยาว prefix ณ จุดนี้
        }
    }
    
    return result;
}