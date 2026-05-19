class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        
        // นับความถี่
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // เรียงลำดับจากมากไปน้อย
        sort(freq.begin(), freq.end(), greater<int>());
        
        unordered_set<int> used;
        int deletions = 0;
        
        for (int f : freq) {
            if (f == 0) continue;
            
            // ลดความถี่ลงจนกว่าจะเจอค่าที่ไม่ถูกใช้
            while (f > 0 && used.count(f)) {
                f--;
                deletions++;
            }
            
            // ถ้ายังมีค่าความถี่เหลือ ให้ mark ว่าใช้แล้ว
            if (f > 0) {
                used.insert(f);
            }
        }
        
        return deletions;
    }
};