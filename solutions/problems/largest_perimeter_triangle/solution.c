// ฟังก์ชันเปรียบเทียบสำหรับ qsort (เรียงจากมากไปน้อย)
int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int largestPerimeter(int* nums, int numsSize) {
    // เรียงจากมากไปน้อย
    qsort(nums, numsSize, sizeof(int), compare);
    
    // ตรวจสอบสามค่าติดกัน
    for (int i = 0; i < numsSize - 2; i++) {
        // ใช้ triangle inequality: ด้านสั้นสองด้านรวมกันต้องมากกว่าด้านที่ยาวที่สุด
        if (nums[i] < nums[i+1] + nums[i+2]) {
            return nums[i] + nums[i+1] + nums[i+2];
        }
    }
    
    return 0;
}