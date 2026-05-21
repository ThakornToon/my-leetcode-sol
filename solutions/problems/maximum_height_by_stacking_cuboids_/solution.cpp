class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        
        // เรียงลำดับมิติภายในแต่ละกล่อง (width <= length <= height)
        // ทำให้ความสูงเป็นค่ามากที่สุด
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        
        // เรียงลำดับกล่องตาม width, length, height น้อยไปมาก
        sort(cuboids.begin(), cuboids.end());
        
        // dp[i] = ความสูงสูงสุดของกองกล่องที่ลงท้ายด้วยกล่อง i (อยู่บนสุด)
        vector<int> dp(n, 0);
        int maxHeight = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2]; // ความสูงของกล่อง i
            for (int j = 0; j < i; j++) {
                // ตรวจสอบว่ากล่อง j วางใต้กล่อง i ได้หรือไม่
                if (cuboids[j][0] <= cuboids[i][0] && 
                    cuboids[j][1] <= cuboids[i][1] && 
                    cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }
        
        return maxHeight;
    }
};