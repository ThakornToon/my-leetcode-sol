class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> rank(26, 26); // กำหนด rank เริ่มต้นเป็น 26 (ใหญ่ที่สุด)
        
        // กำหนด rank ตามลำดับใน order
        for (int i = 0; i < order.size(); i++) {
            rank[order[i] - 'a'] = i;
        }
        
        // เรียงลำดับ s ตาม rank
        sort(s.begin(), s.end(), [&](char a, char b) {
            return rank[a - 'a'] < rank[b - 'a'];
        });
        
        return s;
    }
};