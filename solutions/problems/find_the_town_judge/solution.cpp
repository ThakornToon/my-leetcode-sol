class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);
        
        for (const auto& t : trust) {
            trustCount[t[0]]--;  // ถ้าให้ trust ลดคะแนน
            trustCount[t[1]]++;  // ถ้าได้รับ trust เพิ่มคะแนน
        }
        
        for (int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};