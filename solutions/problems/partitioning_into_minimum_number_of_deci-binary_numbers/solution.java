class Solution {
    public int minPartitions(String n) {
        int maxDigit = 0;
        
        for (int i = 0; i < n.length(); i++) {
            // แปลง char เป็น int
            int digit = n.charAt(i) - '0';
            
            // อัปเดตค่ามากที่สุด
            maxDigit = Math.max(maxDigit, digit);
            
            // optimize: ถ้าเจอ 9 แล้วหยุดได้
            if (maxDigit == 9) {
                return 9;
            }
        }
        
        return maxDigit;

    }
}