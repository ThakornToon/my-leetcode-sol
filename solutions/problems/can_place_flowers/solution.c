bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    
    for (int i = 0; i < flowerbedSize; i++) {
        // ตรวจสอบว่าปลูกได้ไหม
        if (flowerbed[i] == 0) {
            // ตรวจสอบตำแหน่งก่อนหน้าและถัดไป
            int prev = (i == 0) ? 0 : flowerbed[i-1];
            int next = (i == flowerbedSize-1) ? 0 : flowerbed[i+1];
            
            if (prev == 0 && next == 0) {
                flowerbed[i] = 1;  // ปลูกดอกไม้
                count++;
                
                if (count >= n) {
                    return true;
                }
            }
        }
    }
    
    return count >= n;
}