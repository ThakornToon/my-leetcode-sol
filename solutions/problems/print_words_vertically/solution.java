class Solution {
    public List<String> printVertically(String s) {
        String[] words = s.split(" ");
        int maxLen = 0;
        for (String word : words) {
            maxLen = Math.max(maxLen, word.length());
        }
        
        List<String> result = new ArrayList<>();
        
        // สร้าง string แนวตั้ง
        for (int j = 0; j < maxLen; j++) {
            StringBuilder col = new StringBuilder();
            
            for (String word : words) {
                if (j < word.length()) {
                    col.append(word.charAt(j));
                } else {
                    col.append(' ');
                }
            }
            
            // ตัดช่องว่างท้าย
            while (col.length() > 0 && col.charAt(col.length() - 1) == ' ') {
                col.deleteCharAt(col.length() - 1);
            }
            
            result.add(col.toString());
        }

        return result;
    }
}