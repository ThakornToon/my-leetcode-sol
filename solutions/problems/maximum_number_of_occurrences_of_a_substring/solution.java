class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        Map<String, Integer> countMap = new HashMap<>();
        int maxCount = 0;
        
        // ตรวจสอบทุก substring ความยาว minSize (ผลลัพธ์ที่ดีสุด)
        for (int i = 0; i <= n - minSize; i++) {
            String substr = s.substring(i, i + minSize);
            
            // ตรวจสอบจำนวนตัวอักษรที่แตกต่างกัน
            if (countUniqueLetters(substr) <= maxLetters) {
                int count = countMap.getOrDefault(substr, 0) + 1;
                countMap.put(substr, count);
                maxCount = Math.max(maxCount, count);
            }
        }
        
        return maxCount;
    }

    private int countUniqueLetters(String str) {
        boolean[] seen = new boolean[26];
        int unique = 0;
        
        for (int i = 0; i < str.length(); i++) {
            int idx = str.charAt(i) - 'a';
            if (!seen[idx]) {
                seen[idx] = true;
                unique++;
            }
        }
        
        return unique;
    }
}