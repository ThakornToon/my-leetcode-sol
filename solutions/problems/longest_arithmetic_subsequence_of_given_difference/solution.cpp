class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;  // dp[x] = length of subsequence ending with x
        
        int maxLength = 0;
        
        for (int num : arr) {
            // ดูว่ามีตัวก่อนหน้าที่ทำให้ได้ลำดับต่อได้ไหม
            int prev = num - difference;
            
            // ถ้ามีตัวก่อนหน้า, ต่อลำดับได้, มิฉะนั้นเริ่มลำดับใหม่ (ความยาว 1)
            if (dp.count(prev)) {
                dp[num] = dp[prev] + 1;
            } else {
                dp[num] = 1;
            }
            
            // อัพเดทค่าสูงสุด
            maxLength = max(maxLength, dp[num]);
        }
        
        return maxLength;
    }
};