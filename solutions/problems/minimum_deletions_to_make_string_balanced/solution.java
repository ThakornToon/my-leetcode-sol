class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        
        // dp_a: min deletions ending with 'a'
        // dp_b: min deletions ending with 'b'
        int dp_a = 0, dp_b = 0;
        
        // Initialize for first character
        char first = s.charAt(0);
        if (first == 'a') {
            dp_a = 0;
            dp_b = 1;
        } else {
            dp_a = 1;
            dp_b = 0;
        }
        
        // Process remaining characters
        for (int i = 1; i < n; i++) {
            char c = s.charAt(i);
            int new_dp_a, new_dp_b;
            
            if (c == 'a') {
                new_dp_a = dp_a;          // keep 'a'
                new_dp_b = dp_b + 1;      // delete 'a'
            } else { // 'b'
                new_dp_a = dp_a + 1;      // delete 'b'
                new_dp_b = Math.min(dp_a, dp_b); // keep 'b'
            }
            
            dp_a = new_dp_a;
            dp_b = new_dp_b;
        }
        
        return Math.min(dp_a, dp_b);
    }
}