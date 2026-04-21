class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();
        
        // ถ้า k > n ไม่สามารถสร้างได้
        if (k > n) {
            return false;
        }
        
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        // นับจำนวนตัวอักษรที่มีความถี่เป็นเลขคี่
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 == 1) {
                oddCount++;
            }
        }
        
        // palindrome แต่ละอันสามารถมีตัวคี่ได้มากสุด 1 ตัว
        return oddCount <= k;
    }
}