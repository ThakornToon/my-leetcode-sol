class Solution {
private:
    long long memo_cnt[16][10][10];  // จำนวนตัวเลขที่สร้างได้ memo_cnt[pos][prev][curr] : _ _ prev curr ..(จำนวนตัวเลขที่สร้างได้).. 
    long long memo_sum[16][10][10];  // จำนวน waviness ของ memo_sum[pos][prev][curr] : _ _ prev curr ..(จำนวน waviness ได้จากทุกแบบ).. 
    
    // Digit DP ที่ returns {count, sum_of_waviness}
    pair<long long, long long> dfs(int pos, int prev, int curr, bool isLimit, bool isLeading, const string& s) {
        int n = s.length();
        
        // Base case: สร้างเลขครบแล้ว (หลักสุดท้ายสร้างต่อไม่ได้แล้ว ตัวปัจจุบันไม่มี waviness และมีแค่แบบเดียว)
        if (pos == n) return {1, 0};
        
        // Memoization (เฉพาะเมื่อไม่ถูกจำกัดและไม่มี leading zero)
        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            if (memo_cnt[pos][prev][curr] != -1) {
                return {memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]};
            }
        }
        
        long long cnt = 0, sum = 0;
        int maxDigit = isLimit ? s[pos] - '0' : 9;
        
        // ตัวเลขตัวถัดไป
        for (int dig = 0; dig <= maxDigit; dig++) {
            bool newLeading = isLeading && (dig == 0);  // 0 ติดกันตั้งแต่ตัวแรกไหม
            int newPrev = curr;
            int newCurr = newLeading ? -1 : dig;
            
            auto [subCnt, subSum] = dfs(pos + 1, newPrev, newCurr, 
                                        isLimit && (dig == maxDigit), newLeading, s);
            
            // ถ้ามี 3 หลักติดกัน ให้ตรวจสอบ peak/valley ของ curr
            // ถ้ามีจะได้ทั้งหมด memo_cnt[pos+1][curr][newCurr] แบบ
            if (prev >= 0 && curr >= 0) {
                if ((prev < curr && curr > dig) || (prev > curr && curr < dig)) {
                    sum += subCnt;  // contribution +1 สำหรับทุกตัวเลข
                }
            }
            
            // count, sum ของตัวเลขตามหลังที่เป็นไปได้ทั้งหมด
            cnt += subCnt;
            sum += subSum;
        }
        
        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            memo_cnt[pos][prev][curr] = cnt;
            memo_sum[pos][prev][curr] = sum;
        }
        
        return {cnt, sum};
    }
    
    // คำนวณผลรวม waviness ของ [0, num]
    long long sumWavinessUpTo(long long num) {
        if (num < 100) return 0;
        
        string s = to_string(num);
        memset(memo_cnt, -1, sizeof(memo_cnt));
        memset(memo_sum, -1, sizeof(memo_sum));
        
        // pos = 0, curr = -1 เพราะยังไม่ได้เลือกหลักเลย
        auto [_, total] = dfs(0, -1, -1, true, true, s);
        return total;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return sumWavinessUpTo(num2) - sumWavinessUpTo(num1 - 1);
    }
};