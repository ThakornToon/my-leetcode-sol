class Solution {
    public boolean checkStrings(String s1, String s2) {
        int n = s1.length();
        
        Map<Character, Integer> evenDiff = new HashMap<>();
        Map<Character, Integer> oddDiff = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenDiff.put(s1.charAt(i), evenDiff.getOrDefault(s1.charAt(i), 0) + 1);
                evenDiff.put(s2.charAt(i), evenDiff.getOrDefault(s2.charAt(i), 0) - 1);
            } else {
                oddDiff.put(s1.charAt(i), oddDiff.getOrDefault(s1.charAt(i), 0) + 1);
                oddDiff.put(s2.charAt(i), oddDiff.getOrDefault(s2.charAt(i), 0) - 1);
            }
        }
        
        for (int val : evenDiff.values()) {
            if (val != 0) return false;
        }
        for (int val : oddDiff.values()) {
            if (val != 0) return false;
        }
        
        return true;
    }
}