class Solution {
    public int minNumberOfFrogs(String croakOfFrogs) {
        int n = croakOfFrogs.length();
        if (n % 5 != 0) return -1;
        
        int[] count = new int[5];
        int activeFrogs = 0;
        int maxFrogs = 0;
        
        for (char c : croakOfFrogs.toCharArray()) {
            if (c == 'c') {
                count[0]++;
                activeFrogs++;
                maxFrogs = Math.max(maxFrogs, activeFrogs);
            } else if (c == 'r') {
                if (count[0] <= count[1]) return -1;
                count[1]++;
            } else if (c == 'o') {
                if (count[1] <= count[2]) return -1;
                count[2]++;
            } else if (c == 'a') {
                if (count[2] <= count[3]) return -1;
                count[3]++;
            } else if (c == 'k') {
                if (count[3] <= count[4]) return -1;
                count[4]++;
                activeFrogs--;
            } else {
                return -1;
            }
        }
        
        // ตรวจสอบว่าทุกเสียงจบสมบูรณ์
        if (count[0] != count[4] || count[1] != count[4] || 
            count[2] != count[4] || count[3] != count[4]) {
            return -1;
        }
        
        return maxFrogs;
    }
}