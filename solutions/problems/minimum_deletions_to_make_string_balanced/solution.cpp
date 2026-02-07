class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int b_count = 0;
        int deletions = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                // ตัวเลือก: ลบ 'a' นี้ หรือ ลบ 'b' ก่อนหน้านี้ทั้งหมด
                deletions = (deletions + 1 < b_count) ? deletions + 1 : b_count;
            } else { // 'b'
                b_count++;
            }
        }
        
        return deletions;
    }
};