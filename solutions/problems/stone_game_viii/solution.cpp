class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // กรณีพิเศษ: มีแค่ 2 ก้อน
        if (n == 2) {
            return stones[0] + stones[1];
        }

        // prefix sums 
        vector<long long> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + stones[i];
        }
        
        // dp[i] = เมื่อหินเหลือตั้งแต่ i จนถึง n-1 จะหยิบได้ดีสุดเท่าไร (dp[n-1] = 0 ไม่มีหินเหลือ)
        // 0 ถึง i คือหนึ่งก้อน
        vector<long long> dp(n, 0);
        
        // เริ่มจากด้านขวาสุด
        // maxVal = max(prefix[j] - dp[j+1]) สำหรับ j >= i+1
        long long maxVal = prefix[n-1] - 0;  // หยิบ 0 ถึง n-1 เลย (อีกคนหยิบไม่ได้แล้ว)
        dp[n-1] = maxVal;
        
        // วนจาก n-2 ลงไปถึง 1 (ไม่รวม 0 เพราะเทิร์นแรกห้ามเลือก j=0) คิดจากตอนจบเกมขึ้นมา
        for (int i = n-2; i >= 1; i--) {
            // พิจารณาเลือกถึง i อีกคนจะเหลือตั้งแต่ i+1 จนถึง n-1
            long long current = prefix[i] - dp[i+1];
            // หรือมีวิธีที่ดีกว่า prefix[x] - dp[x+1], x > i
            maxVal = max(maxVal, current);
            dp[i] = maxVal;
        }
        
        return (int)maxVal;
    }
};