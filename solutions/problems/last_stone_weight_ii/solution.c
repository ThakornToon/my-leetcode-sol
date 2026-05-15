int lastStoneWeightII(int* stones, int stonesSize) {
    int total = 0;
    for (int i = 0; i < stonesSize; i++) {
        total += stones[i];
    }
    
    // พยายามให้หะกล้างกันได้ดีที่สุด (แบ่งสองส่วนให้ใกล้ target ที่สุด)
    int target = total / 2;
    
    // dp[j] = สามารถสร้างจำนวน j นั้นได้ไหม
    bool* dp = (bool*)calloc(target + 1, sizeof(bool));
    dp[0] = true;  // เริ่มที่ 0 
    
    for (int i = 0; i < stonesSize; i++) {
        // สร้าง j จาก j - stones[i] ได้ไหมด้วยหินก้อน i
        for (int j = target; j >= stones[i]; j--) {
            if (dp[j - stones[i]]) {
                dp[j] = true;
            }
        }
    }
    
    // หาค่าที่ใกล้ target ที่สุดเพื่อเอามาลบกับอีกส่วนให้ได้น้อยที่สุด
    int closest = 0;
    for (int i = target; i >= 0; i--) {
        if (dp[i]) {
            closest = i;
            break;
        }
    }
    
    free(dp);
    return total - 2 * closest;  // (total - closest) - closest
}