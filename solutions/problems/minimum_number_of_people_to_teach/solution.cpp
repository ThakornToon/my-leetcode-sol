class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // แปลงภาษาเป็น unordered_set เพื่อ O(1) lookup
        vector<unordered_set<int>> knows(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i].insert(lang);
            }
        }
        
        // หาเพื่อนคู่ที่ยังสื่อสารไม่ได้
        vector<bool> needTeach(m, false);
        int needTeachCount = 0;
        
        for (auto& f : friendships) {
            int a = f[0] - 1;
            int b = f[1] - 1;
            
            // ตรวจสอบภาษากลาง
            bool canCommunicate = false;
            for (int lang : knows[a]) {
                if (knows[b].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            
            if (!canCommunicate) {
                if (!needTeach[a]) {
                    needTeach[a] = true;
                    needTeachCount++;
                }
                if (!needTeach[b]) {
                    needTeach[b] = true;
                    needTeachCount++;
                }
            }
        }
        
        if (needTeachCount == 0) return 0;
        
        // ลองสอนแต่ละภาษา
        int minPeople = needTeachCount;
        
        for (int lang = 1; lang <= n; lang++) {
            int teachCount = 0;
            for (int person = 0; person < m; person++) {
                if (needTeach[person] && !knows[person].count(lang)) {
                    teachCount++;
                }
            }
            minPeople = min(minPeople, teachCount);
        }
        
        return minPeople;
    }
};