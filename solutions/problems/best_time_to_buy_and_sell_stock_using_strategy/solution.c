int max(int a, int b) {
    return a > b ? a : b;
}
long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k) {
    // prefix[i] ผลรวม prices i ตัวแรก
    // ผลรวม index i..=j : prefix[j + 1] - prefix[i]
    long long* prefix = (long long*)malloc((pricesSize + 1) * sizeof(long long));
    prefix[0] = 0;
    long long base_profit = 0;
    for (int i = 0; i < pricesSize; i++) {
        prefix[i + 1] = prefix[i] + prices[i];
        base_profit += strategy[i] * prices[i];
    }

    int half_k = k / 2;
    long long original_sum = 0; // แบบไม่ได้ทำอะไรเลย
    long long modified_sum = 0; // แบบมีการปรับค่า
    long long max_change = 0; 
    
    // สำหรับช่วง [start, start+k-1]:
    // change = (sum(prices[start+half_k .. start+k-1]) - sum(strategy[i]*prices[i] สำหรับ i ในช่วง))
    
    // สร้าง window แรก
    for (int i = 0; i < k; i++) {
        original_sum += (long long)strategy[i] * prices[i];
        if (i >= half_k) {
            modified_sum += prices[i];  // ครึ่งหลังเปลี่ยนเป็น sell (1 * price)
        }
        // ครึ่งแรกเปลี่ยนเป็น hold (0 * price) = 0 ไม่ต้องบวก
    }
    
    long long current_change = modified_sum - original_sum;
    max_change = current_change > 0 ? current_change : 0;
    
    // Sliding window ไปจนสุด
    for (int start = 1; start <= pricesSize - k; start++) {
        int end = start + k - 1;
        
        // ออกจาก window: index start-1
        original_sum -= strategy[start - 1] * prices[start - 1];
        // ถ้า element ที่ออกเป็นครึ่งแรกของ window เก่า
        // ใน modification มันจะเป็น hold (0) ไม่ต้องทำอะไร
        // ถ้า element ที่ออกเป็นครึ่งหลังของ window เก่า
        modified_sum -= prices[start + half_k - 1];
        
        // เข้ามาใน window: index end
        original_sum += strategy[end] * prices[end];
        // ถ้า element ที่เข้ามาเป็นครึ่งแรกของ window ใหม่
        // ใน modification มันจะเป็น hold (0) ไม่ต้องบวก
        // ถ้า element ที่เข้ามาเป็นครึ่งหลังของ window ใหม่
        modified_sum += prices[end];
        
        current_change = modified_sum - original_sum;
        if (current_change > max_change) {
            max_change = current_change;
        }
    }
    
    free(prefix);
    return base_profit + max_change; // การปรับที่ทำให้ค่าเพิ่มมากที่สุด
}