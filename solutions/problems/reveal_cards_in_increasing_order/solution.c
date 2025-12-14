/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    // 1. เรียงจากน้อยไปมาก
    qsort(deck, deckSize, sizeof(int), compare);
    
    // 2. สร้างผลลัพธ์
    int* result = (int*)malloc(deckSize * sizeof(int));
    *returnSize = deckSize;
    
    // 3. กำหนดทุกตำแหน่งเป็น -1 (ยังไม่ได้ใส่)
    for (int i = 0; i < deckSize; i++) {
        result[i] = -1;
    }
    
    // 4. Greedy: ใส่เลขน้อยในตำแหน่งที่ว่าง สลับไปมา
    int deckIndex = 0;
    int resultIndex = 0;
    
    while (deckIndex < deckSize) {
        // หาตำแหน่งที่ว่างตัวแรก
        while (resultIndex < deckSize && result[resultIndex] != -1) {
            resultIndex++;
        }
        
        if (resultIndex >= deckSize) break;
        
        // ใส่ไพ่
        result[resultIndex] = deck[deckIndex];
        deckIndex++;
        
        // ข้ามช่องว่าง 1 ช่องสำหรับไพ่ถัดไป
        if (deckIndex < deckSize) {
            // หาช่องว่างถัดไป
            int emptyCount = 0;
            do {
                resultIndex = (resultIndex + 1) % deckSize;
                if (result[resultIndex] == -1) {
                    emptyCount++;
                }
            } while (emptyCount < 2); // ข้าม 1 ช่องว่าง
        }
    }
    
    return result;
}