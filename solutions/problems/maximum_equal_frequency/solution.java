class Solution {
    public int maxEqualFreq(int[] nums) {
        // count: เก็บความถี่ของตัวเลขแต่ละตัว
        Map<Integer, Integer> count = new HashMap<>();
        // freqCount: เก็บจำนวนตัวเลขที่มีความถี่นั้นๆ
        Map<Integer, Integer> freqCount = new HashMap<>();
        
        int maxFreq = 0;
        int result = 0;
        
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            // หาความถี่ก่อนหน้านี้ของค่าปัจจุบัน
            int currentFreq = count.getOrDefault(num, 0);
            
            // ลดความถี่เก่าออก
            if (currentFreq > 0) {
                freqCount.put(currentFreq, freqCount.get(currentFreq) - 1);
                if (freqCount.get(currentFreq) == 0) {
                    freqCount.remove(currentFreq);
                }
            }
            
            // เพิ่มความถี่ใหม่
            count.put(num, currentFreq + 1);
            int newFreq = count.get(num);
            freqCount.put(newFreq, freqCount.getOrDefault(newFreq, 0) + 1);
            
            // อัปเดตความถี่สูงสุด
            maxFreq = Math.max(maxFreq, newFreq);
            
            // ตรวจสอบเงื่อนไขที่ถูกต้อง
            boolean isValid = false;
            
            // กรณี 1: ความถี่ทั้งหมดเป็น 1
            if (maxFreq == 1) {
                isValid = true;
            }
            // กรณี 2: มีความถี่เดียวที่ปรากฏ
            else if (freqCount.size() == 1 && freqCount.get(maxFreq) == 1) {
                isValid = true;
            }
            // กรณี 3: มีความถี่ที่แตกต่างกันสองค่า
            else if (freqCount.size() == 2) {
                // ดึง key ทั้งสอง
                Integer[] keys = freqCount.keySet().toArray(new Integer[0]);
                int freq1 = keys[0];
                int freq2 = keys[1];
                
                // กรณี 3a: ความถี่สูงสุดมากกว่าความถี่ต่ำสุดอยู่ 1 และปรากฏเพียงครั้งเดียว
                if (maxFreq - 1 == Math.min(freq1, freq2) && freqCount.get(maxFreq) == 1) {
                    isValid = true;
                }
                // กรณี 3b: มีความถี่ 1 ปรากฏเพียงครั้งเดียว
                else if (freqCount.containsKey(1) && freqCount.get(1) == 1) {
                    isValid = true;
                }
            }
            
            // บันทึกผลลัพธ์หากเงื่อนไขถูกต้อง
            if (isValid) {
                result = i + 1; // ความยาว prefix ณ จุดนี้
            }
        }
        
        return result;
    }
}