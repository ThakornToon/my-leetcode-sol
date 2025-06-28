bool canCross(int* stones, int stonesSize) {
    bool** dp = (bool**)calloc(stonesSize, sizeof(bool*)); 
    int size = 0;
    for (int i = 0; i < stonesSize; i++) { // หินจำนวน stonesSize ระยะกระโดดที่เป็นไปได้มากสุดคือ 0..=stonesSize
        dp[size++] = (bool*)calloc(stonesSize + 1, sizeof(bool));
    }
    dp[0][1] = true; // หินก้อนแรกมีการกระโดดได้แค่ 1
    
    for (int i = 1; i < stonesSize; ++i) { // ความเป็นไปได้ในการเดินทางไปยังหินก้อนที่ i 
        for (int j = 0; j < i; ++j) { // ดูก้อนหินก่อนหน้านี้
            int diff = stones[i] - stones[j]; // ระยะห่างระหว่างก้อนหิน
            if (diff > stonesSize || !dp[j][diff]) { // ดูจากหินก้อนที่แล้วว่าสามารถกระโดดในระยะนี้ได้ไหม แล้วถ้าระยะมากกว่า stonesSize ก็เป็นไปไม่ได้เลย
                continue;
            }
            if (i == stonesSize - 1) { // มาถึงก้อนสุดท้ายได้
                return true;
            }
            // mark ระยะกระโดดออกที่เป็นไปได้
            dp[i][diff] = true;
            if (diff - 1 >= 0) {
                dp[i][diff - 1] = true;
            }
            if (diff + 1 <= stonesSize) {
                dp[i][diff + 1] = true;
            }
        }
    }

    return false;
}