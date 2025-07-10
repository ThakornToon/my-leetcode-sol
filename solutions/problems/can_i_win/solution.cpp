class Solution {
private: 
    unordered_map<int, bool> memo;
    
    bool backtrack(int maxNum, int target, int used) {
        if (memo.count(used)) return memo[used]; // หากเคยคิดเก็บใน map ไปแล้ว
        
        for (int i = 0; i < maxNum; ++i) {
            if (!(used & (1 << i))) { // ดูตัวเลขที่ยังไม่เคยใช้
                int current = i + 1;
                // ถ้าเลือกตัวนี้แล้วชนะ หรือทำให้คู่ต่อสู้แพ้
                if (current >= target || !backtrack(maxNum, target - current, used | (1 << i))) {
                    memo[used] = true;
                    return true;
                }
            }
        }
        
        memo[used] = false;
        return false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        if (maxChoosableInteger >= desiredTotal) return true;
        
        return backtrack(maxChoosableInteger, desiredTotal, 0);
    }
};