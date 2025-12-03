class Solution {
public:
    int kSimilarity(string s1, string s2) {
        unordered_map<string, int> memo;
        return backtrack(s1, s2, 0, memo);
    }
private:
    int backtrack(string s1, string s2, int pos, unordered_map<string, int>& memo) {
        if (s1 == s2) return 0;
        
        string key = s1 + "#" + to_string(pos);
        if (memo.count(key)) return memo[key];
        
        int n = s1.size();
        
        // หาตำแหน่งแรกที่ไม่ตรงกัน
        while (pos < n && s1[pos] == s2[pos]) {
            pos++;
        }
        
        if (pos == n) return 0;
        
        int minSwaps = INT_MAX;
        
        // ลอง swap กับทุกตำแหน่งที่อยู่หลัง
        for (int i = pos + 1; i < n; i++) {
            // เงื่อนไขการ swap:
            // 1. s1[i] ต้องเท่ากับ s2[pos] (ทำให้ตำแหน่ง pos ถูกต้อง)
            // 2. s1[i] ต้องไม่เท่ากับ s2[i] (swap แล้วไม่ทำให้ตำแหน่ง i พัง)
            if (s1[i] == s2[pos] && s1[i] != s2[i]) {
                swap(s1[pos], s1[i]);
                
                int nextSwaps = 1 + backtrack(s1, s2, pos + 1, memo);
                minSwaps = min(minSwaps, nextSwaps);
                
                swap(s1[pos], s1[i]);  // backtrack
                
                // Greedy optimization: ถ้า direct swap ดีสุดไม่ต้องคิดต่อ
                if (s1[pos] == s2[i]) {
                    break;
                }
            }
        }
        
        memo[key] = (minSwaps == INT_MAX) ? 0 : minSwaps;
        return memo[key];
    }
};