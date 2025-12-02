int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // น้อยไปมาก
}

bool isNStraightHand(int* hand, int handSize, int groupSize) {
    // ตรวจสอบจำนวนไพ่
    if (handSize % groupSize != 0) return false;
    
    // คัดลอกและเรียงลำดับไพ่
    qsort(hand, handSize, sizeof(int), compare);
    
    // ใช้ array ในการติดตามว่าไพ่ถูกใช้ไปแล้วหรือยัง
    bool* used = (bool*)calloc(handSize, sizeof(bool));
    
    for (int i = 0; i < handSize; i++) {
        if (used[i]) continue;  // ข้ามไพ่ที่ใช้ไปแล้ว
        
        int current = hand[i];
        int count = 1;
        used[i] = true;
        
        // หาไพ่ที่เรียงต่อจาก current
        for (int j = i + 1; j < handSize && count < groupSize; j++) {
            if (!used[j] && hand[j] == current + count) {
                used[j] = true;
                count++;
            }
        }
        
        // ถ้าหาไพ่ไม่ครบ groupSize
        if (count != groupSize) {
            free(used);
            return false;
        }
    }
    
    free(used);
    return true;
}