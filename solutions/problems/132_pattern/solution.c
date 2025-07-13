bool find132pattern(int* nums, int numsSize) {
    int* st = (int*)malloc(numsSize * sizeof(int));
    int s2 = INT_MIN; 
    int stackIdx = -1;
        
    for (int i = numsSize - 1; i >= 0; i--) {
        // ถ้าเจอ nums[i] ที่น้อยกว่า s2 แสดงว่าพบ pattern
        if (nums[i] < s2) {
            return true;
        }
            
        // รักษา stack ให้เรียงจากมากไปน้อย
        while (stackIdx >= 0 && st[stackIdx] < nums[i]) { // จะมี s2 ก็ต่อเมื่อหา s3 ได้แล้ว
            s2 = st[stackIdx];  // อัพเดท s2 ให้เป็นค่าที่ใหญ่ที่สุดที่เป็นไปได้
            stackIdx--;
        }
        stackIdx++;
        st[stackIdx] = nums[i];
    }
    return false;
}