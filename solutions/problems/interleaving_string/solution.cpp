class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        // ถ้าความยาวรวมไม่เท่ากัน
        if (len1 + len2 != len3) {
            return false;
        }
        
        // ใช้ 1D DP array เพื่อประหยัดพื้นที่
        // dp[j] = เป็นไปได้ไหมที่จะสร้าง s3[0..i+j-1] 
        //         จาก s1[0..i-1] และ s2[0..j-1]
        vector<bool> dp(len2 + 1, false);
        
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;  // base case
                    continue;
                }
                
                int k = i + j - 1;
                bool canForm = false;
                
                // ตรวจสอบการใช้อักษรจาก s1
                if (i > 0 && dp[j] && s1[i-1] == s3[k]) {
                    canForm = true;
                }
                // ตรวจสอบการใช้อักษรจาก s2
                else if (j > 0 && dp[j-1] && s2[j-1] == s3[k]) {
                    canForm = true;
                }
                
                dp[j] = canForm;
            }
        }
        
        return dp[len2];
    }
};