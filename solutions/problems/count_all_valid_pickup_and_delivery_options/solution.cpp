/*
แนวคิด: ใช้ DP
- เมื่อมี n-1 รายการ จำนวนวิธี = dp[n-1]
- เพิ่มรายการที่ n: มี Pn และ Dn
- แทรก Pn: มี (2n-1) ตำแหน่ง (เพราะมี 2n-2 ตัว + 1 ช่องแรก)
- แทรก Dn: ต้องอยู่หลัง Pn โดยลำดับตอนนี้ยาว (2n-1) มีช่องว่าง 2n → มี n ตำแหน่ง (โดยเฉลี่ย)
- ดังนั้น dp[n] = dp[n-1] * (2n-1) * n
*/

class Solution {
private:
    const int MOD = 1000000007;

public:
    int countOrders(int n) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] * (2 * i - 1) % MOD;
            dp[i] = dp[i] * i % MOD;
        }
        
        return (int)dp[n];
    }
};