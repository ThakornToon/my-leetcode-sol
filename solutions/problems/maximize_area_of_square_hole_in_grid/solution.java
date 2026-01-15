class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        // เรียงลำดับ bars
        Arrays.sort(hBars);
        Arrays.sort(vBars);
        
        // หาจำนวน consecutive bars สูงสุดสำหรับ horizontal
        int maxH = findMaxConsecutive(hBars);
        
        // หาจำนวน consecutive bars สูงสุดสำหรับ vertical
        int maxV = findMaxConsecutive(vBars);
        
        // side length = min(maxH, maxV) + 1
        int side = Math.min(maxH, maxV) + 1;
        return side * side;
    }
    
    private int findMaxConsecutive(int[] bars) {
        if (bars.length == 0) {
            return 0;
        }
        
        int maxCount = 1;
        int current = 1;
        
        for (int i = 1; i < bars.length; i++) {
            if (bars[i] == bars[i-1] + 1) {
                // bars ติดกัน
                current++;
                maxCount = Math.max(maxCount, current);
            } else {
                // หยุด consecutive
                current = 1;
            }
        }
        
        return Math.max(maxCount, current);
    }
}