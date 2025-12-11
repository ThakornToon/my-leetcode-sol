class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size();
        int n = target.size();
        
        vector<int> result;
        string current = target;
        
        auto canStamp = [&](int pos) -> bool {
            if (pos < 0 || pos > n - m) return false;
            
            bool allQuestion = true;
            bool anyMatch = false;
            
            for (int i = 0; i < m; i++) {
                if (current[pos + i] != '?') {
                    allQuestion = false;
                    if (current[pos + i] == stamp[i]) {
                        anyMatch = true;
                    } else {
                        return false;
                    }
                }
            }
            
            return !allQuestion && anyMatch;
        };
        
        auto doStamp = [&](int pos) {
            for (int i = 0; i < m; i++) {
                current[pos + i] = '?';
            }
            result.push_back(pos);
        };
        
        bool changed = true;
        while (changed) {
            changed = false;
            
            for (int i = 0; i <= n - m; i++) {
                if (canStamp(i)) {
                    doStamp(i);
                    changed = true;
                    // หลังจาก stamp แล้ว ให้เริ่มใหม่
                    break;
                }
            }
        }
        
        // ตรวจสอบว่าเป็น '?' ทั้งหมดหรือไม่
        for (char c : current) {
            if (c != '?') {
                return {};
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};