class Solution {
private:
    const int MOD = 1000000007;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        
        // dp[f][i] = จำนวนวิธีที่ใช้ fuel = f แล้วจบที่ city i
        vector<vector<long long>> dp(fuel + 1, vector<long long>(n, 0));
        
        // เริ่มต้น: ที่ fuel = 0 อยู่ที่ start
        dp[0][start] = 1;
        
        long long result = 0;
        
        // ค่อยๆ เพิ่ม fuel ทีละ 1
        for (int f = 0; f <= fuel; f++) {
            // ย้อนจาก i ไป j
            for (int i = 0; i < n; i++) {
                if (dp[f][i] == 0) continue;
                
                // ถ้าอยู่ที่ finish ให้เก็บผลลัพธ์
                if (i == finish) {
                    result = (result + dp[f][i]) % MOD;
                }
                
                // ลองไปเมืองอื่นๆ
                for (int j = 0; j < n; j++) {
                    if (j == i) continue;
                    
                    int cost = abs(locations[i] - locations[j]);
                    if (f + cost <= fuel) {
                        dp[f + cost][j] = (dp[f + cost][j] + dp[f][i]) % MOD;
                    }
                }
            }
        }
        
        return result;
    }
};