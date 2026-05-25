class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n-1] != '0') return false;
        
        // dp[i] = สามารถไปถึง index i ได้หรือไม่
        // dp[i] = true ถ้ามี j ในช่วง [i-maxJump, i-minJump] ที่ dp[j] == true
        // ใช้ prefix sum เพื่อหาว่ามี dp[j] == true ในช่วงนั้นหรือไม่
        vector<bool> dp(n, false);
        vector<int> prefix(n + 1, 0); // prefix sum of dp
        
        dp[0] = true;
        prefix[1] = 1;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                // ดูว่าโดดมาที i จากตำแหน่งก่อนหน้าได้ไหม
                int left = max(0, i - maxJump);
                int right = i - minJump;

                // right < 0 แปลว่าโดดมาไม่ได้
                // ตรวจว่าตั้งแต่ left..right สามารถมาจากตำแหน่งเริ่มต้นได้ไหม
                if (right >= 0 && prefix[right + 1] - prefix[left] > 0) {
                    dp[i] = true;
                }
            }
            
            prefix[i + 1] = prefix[i] + (dp[i] ? 1 : 0);
        }
        
        return dp[n - 1];
    }
};