class Solution {
    public int minOperations(String s) {
        int n = s.length();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (i % 2 == 0) {
                if (c != '0') count++;
            } else {
                if (c != '1') count++;
            }
        }
        
        return Math.min(count, n - count);
    }
}