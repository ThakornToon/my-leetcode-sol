class Solution {
    public int longestBalanced(String s) {
        int n = s.length();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];
            int distinct = 0;
            int targetFreq = -1;
            
            for (int j = i; j < n; j++) {
                int idx = s.charAt(j) - 'a';
                if (freq[idx] == 0) {
                    distinct++;
                }
                freq[idx]++;
                
                // ถ้ามี distinct มากกว่า 26 หรือความยาวเกิน maxLen ที่เหลือก็ไม่มีประโยชน์
                if (distinct > 26) break;
                
                // ตรวจสอบความถี่ทุกตัว
                if (distinct == 1) {
                    targetFreq = freq[idx];
                    maxLen = Math.max(maxLen, j - i + 1);
                } else {
                    int firstFreq = -1;
                    boolean balanced = true;
                    
                    for (int c = 0; c < 26; c++) {
                        if (freq[c] > 0) {
                            if (firstFreq == -1) {
                                firstFreq = freq[c];
                            } else if (freq[c] != firstFreq) {
                                balanced = false;
                                break;
                            }
                        }
                    }
                    
                    if (balanced) {
                        maxLen = Math.max(maxLen, j - i + 1);
                    }
                }
            }
        }
        
        return maxLen;
    }
}