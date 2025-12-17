int brokenCalc(int startValue, int target) {
    int operations = 0;
    
    // ทำงานจาก target กลับไปหา startValue
    while (target > startValue) {
        if (target % 2 == 0) {
            // ถ้า target เป็นเลขคู่: ย้อนกลับการคูณ 2
            target /= 2;
        } else {
            // ถ้า target เป็นเลขคี่: ย้อนกลับการลบ 1
            target++;
        }
        operations++;
    }
    
    // ตอนนี้ target ≤ startValue
    // เราต้องลบ 1 หลายครั้งเพื่อให้เหลือ startValue
    operations += (startValue - target);
    
    return operations;
}