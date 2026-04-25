#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int n = cardPointsSize;
    int totalSum = 0;
    
    // คำนวณผลรวมทั้งหมด
    for (int i = 0; i < n; i++) {
        totalSum += cardPoints[i];
    }
    
    // ถ้า k == n ให้คืนค่าผลรวมทั้งหมด
    if (k == n) return totalSum;
    
    int windowSize = n - k;
    int windowSum = 0;
    
    // คำนวณ window แรก
    for (int i = 0; i < windowSize; i++) {
        windowSum += cardPoints[i];
    }
    
    int minWindowSum = windowSum;
    
    // เลื่อน window หาค่าต่ำสุด
    for (int i = windowSize; i < n; i++) {
        windowSum = windowSum - cardPoints[i - windowSize] + cardPoints[i];
        minWindowSum = MIN(minWindowSum, windowSum);
    }
    
    return totalSum - minWindowSum;
}