class Solution {
private:
    int maxCount = 0;
    
    void dfs(const string& s, int start, unordered_set<string>& used, int count) {
        int n = s.length();
        
        // ถ้าไปถึงจุดสิ้นสุด
        if (start == n) {
            maxCount = max(maxCount, count);
            return;
        }
        
        // Pruning: ถ้า count + (n - start) <= maxCount ตัดทิ้ง
        // (ไม่สามารถทำได้ดีกว่า maxCount แล้ว)
        if (count + (n - start) <= maxCount) {
            return;
        }
        
        // ลองทุกความยาว substring ที่เป็นไปได้
        for (int end = start + 1; end <= n; end++) {
            string sub = s.substr(start, end - start);
            
            // ถ้า substring นี้ไม่เคยถูกใช้
            if (used.find(sub) == used.end()) {
                used.insert(sub);
                dfs(s, end, used, count + 1);
                used.erase(sub); // backtrack
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> used;
        dfs(s, 0, used, 0);
        return maxCount;
    }
};