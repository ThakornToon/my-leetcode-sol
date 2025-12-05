int minEatingSpeed(int* piles, int pilesSize, int h) {
    // หาค่าสูงสุดใน piles
    int maxPile = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > maxPile) {
            maxPile = piles[i];
        }
    }
    
    int low = 1;
    int high = maxPile;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // คำนวณเวลาที่ใช้
        long long hours = 0;  // ใช้ long long เพื่อป้องกัน overflow
        for (int i = 0; i < pilesSize; i++) {
            // hours += ceil((double)piles[i] / mid)
            hours += (piles[i] + mid - 1) / mid;
            
            // Optimization: ถ้า hours > h แล้ว สามารถหยุดลูปได้
            if (hours > h) {
                break;
            }
        }
        
        if (hours <= h) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}