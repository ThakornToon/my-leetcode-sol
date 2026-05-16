class Solution {
private:
    const int MOD = 1000000007;
public:
    int numWays(string s) {
        int n = s.length();
        long long totalOnes = 0;
        
        // นับจำนวน '1' ทั้งหมดในสตริง
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        // กรณีที่ 1: จำนวน '1' หาร 3 ไม่ลงตัว -> ไม่สามารถแบ่งได้
        if (totalOnes % 3 != 0) return 0;
        
        // กรณีที่ 2: ไม่มี '1' เลย -> ใช้สูตร Cnr (n-1 เลือก 2)
        if (totalOnes == 0) {
            long long result = (long long)(n - 1) * (n - 2) / 2;
            return (int)(result % MOD);
        }
        
        long long onesPerPart = totalOnes / 3;
        long long countFirstCut = 0;   // จำนวนตำแหน่งที่เป็นไปได้สำหรับตัดครั้งแรก
        long long countSecondCut = 0;  // จำนวนตำแหน่งที่เป็นไปได้สำหรับตัดครั้งที่สอง
        long long prefixOnes = 0;
        
        // หาตำแหน่งที่เป็นไปได้สำหรับการตัดครั้งแรก
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') prefixOnes++;
            
            if (prefixOnes == onesPerPart) {
                countFirstCut++;  // นับจำนวน '0' ในช่องว่างนี้
            } else if (prefixOnes == onesPerPart + 1) {
                break;  // เจอ '1' ตัวแรกของส่วนที่สองแล้ว หยุดนับ
            }
        }
        
        prefixOnes = 0;
        // หาตำแหน่งที่เป็นไปได้สำหรับการตัดครั้งที่สอง (นับจากด้านขวา)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') prefixOnes++;
            
            if (prefixOnes == onesPerPart) {
                countSecondCut++;  // นับจำนวน '0' ในช่องว่างนี้
            } else if (prefixOnes == onesPerPart + 1) {
                break;  // เจอ '1' ตัวแรกของส่วนที่สามแล้ว หยุดนับ
            }
        }
        
        long long result = (countFirstCut * countSecondCut) % MOD;
        return (int)result;
    }
};