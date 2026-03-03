class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        // เรียงตาม l จากน้อยไปมาก, ถ้า l เท่ากันให้เรียง r จากมากไปน้อย
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            return b[1] - a[1];
        });
        
        int count = 1;
        int[] current = intervals[0];
        
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][1] > current[1]) {
                // ไม่ถูก cover
                count++;
                current = intervals[i];
            }
            // ถ้า intervals[i][1] <= current[1] → ถูก cover
        }
        
        return count;
    }
}