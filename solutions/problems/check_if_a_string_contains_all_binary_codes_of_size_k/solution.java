class Solution {
    public boolean hasAllCodes(String s, int k) {
        int n = s.length();
        int total = 1 << k;
        
        if (n < total + k - 1) {
            return false;
        }
        
        boolean[] seen = new boolean[total];
        int hash = 0;
        int mask = total - 1;
        
        // คำนวณ hash สำหรับ k ตัวแรก
        for (int i = 0; i < k; i++) {
            hash = (hash << 1) | (s.charAt(i) - '0');
        }
        seen[hash] = true;
        int count = 1;
        
        // ใช้ sliding window
        for (int i = k; i < n; i++) {
            hash = ((hash << 1) & mask) | (s.charAt(i) - '0');
            if (!seen[hash]) {
                seen[hash] = true;
                count++;
            }
        }
        
        return count == total;
    }
}