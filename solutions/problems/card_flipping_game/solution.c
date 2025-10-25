int flipgame(int* fronts, int frontsSize, int* backs, int backsSize) {
    int bad[2001] = {0}; // 0 = not bad, 1 = bad
    int n = frontsSize;
    
    // เก็บเลขที่ปรากฏทั้งสองด้านของบัตรเดียวกัน
    for (int i = 0; i < n; i++) {
        if (fronts[i] == backs[i]) {
            bad[fronts[i]] = 1;
        }
    }
    
    int answer = INT_MAX;
    
    // ดูทุกเลขใน fronts และ backs
    for (int i = 0; i < n; i++) {
        if (!bad[fronts[i]]) {
            if (fronts[i] < answer) {
                answer = fronts[i];
            }
        }
        if (!bad[backs[i]]) {
            if (backs[i] < answer) {
                answer = backs[i];
            }
        }
    }
    
    return answer == INT_MAX ? 0 : answer;
}