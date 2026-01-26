class Solution {
    public int maxLength(List<String> arr) {
        // แปลงสตริงเป็น masks
        List<Integer> masks = new ArrayList<>();
        List<Integer> lengths = new ArrayList<>();
        
        for (String s : arr) {
            int mask = 0;
            boolean valid = true;
            
            for (char c : s.toCharArray()) {
                int bit = 1 << (c - 'a');
                
                // ตรวจสอบตัวอักษรซ้ำในสตริงเดียวกัน
                if ((mask & bit) != 0) {
                    valid = false;
                    break;
                }
                
                mask |= bit;
            }
            
            if (valid) {
                masks.add(mask);
                lengths.add(s.length());
            }
        }
        
        // ใช้ backtracking
        int[] maxLen = {0};
        backtrack(masks, lengths, 0, 0, 0, maxLen);
        
        return maxLen[0];
    }
    
    private void backtrack(List<Integer> masks, List<Integer> lengths,
                          int index, int currentMask, 
                          int currentLength, int[] maxLen) {
        // อัปเดตค่าสูงสุด
        if (currentLength > maxLen[0]) {
            maxLen[0] = currentLength;
        }
        
        // ฐาน: ตรวจสอบครบทุกสตริงแล้ว
        if (index == masks.size()) {
            return;
        }
        
        // 1. ไม่เลือกสตริงนี้
        backtrack(masks, lengths, index + 1, 
                  currentMask, currentLength, maxLen);
        
        // 2. เลือกสตริงนี้ (ถ้าไม่ชนกับ masks ที่มีอยู่)
        if ((currentMask & masks.get(index)) == 0) {
            backtrack(masks, lengths, index + 1,
                     currentMask | masks.get(index),
                     currentLength + lengths.get(index),
                     maxLen);
        }
    }
}