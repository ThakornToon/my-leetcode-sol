class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // ตำแหน่งของแต่ละตัวอักษรว่ามีที่ไหนบ้าง
        unordered_map<char, vector<int>> char_pos;
        for (int i = 0; i < ring.size(); i++) {
            char_pos[ring[i]].push_back(i);
        }
        
        // dp[i][j] รำนวนขั้นต่ำที่ต้องใช้เพื่อพิมพ์ i + 1 ตัวอักษรแรกของ key เมื่ออักษรปัจจุบันของ ring อยู่ที่ตำแหน่ง j
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        // ตัวอักษรตัวแรก
        for (int j : char_pos[key[0]]) {
            dp[0][j] = min(j, n - j) + 1; // หมุนไปที่ตำแหน่ง j โดยดูว่าทวนหรือตามเข็มดีกว่า
        }
        
        // พิจารณาจนกว่าจะครบทุกตัวใน key
        for (int i = 1; i < m; i++) {
            // ตำแหน่งตัวอักษรที่ต้องการจะไปที่เป็นไปได้
            for (int j : char_pos[key[i]]) {
                // ตำแหน่งตัวอักษรใน key ตัวก่อนหน้าที่เป็นไปได้มาคิด
                for (int k : char_pos[key[i-1]]) {
                    int distance = abs(j - k);
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + min(distance, n - distance) + 1); 
                }
            }
        }
        
        return *min_element(dp.back().begin(), dp.back().end());
    }
};