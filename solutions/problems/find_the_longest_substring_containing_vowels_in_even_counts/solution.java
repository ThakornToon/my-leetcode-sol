class Solution {
    public int findTheLongestSubstring(String s) {
        int n = s.length();
        
        // กำหนด bit สำหรับสระแต่ละตัว
        int[] vowelMask = new int[26];
        vowelMask['a' - 'a'] = 1 << 0;
        vowelMask['e' - 'a'] = 1 << 1;
        vowelMask['i' - 'a'] = 1 << 2;
        vowelMask['o' - 'a'] = 1 << 3;
        vowelMask['u' - 'a'] = 1 << 4;
        
        // เก็บตำแหน่งแรกที่พบ mask แต่ละค่า (2^5 = 32)
        int[] firstPos = new int[32];
        Arrays.fill(firstPos, -1);
        
        int mask = 0;
        int maxLen = 0;
        firstPos[0] = 0;
        
        for (int i = 0; i < n; i++) {
            mask ^= vowelMask[s.charAt(i) - 'a'];
            
            if (firstPos[mask] != -1) {
                maxLen = Math.max(maxLen, i + 1 - firstPos[mask]);
            } else {
                firstPos[mask] = i + 1;
            }
        }
        
        return maxLen;
    }
}