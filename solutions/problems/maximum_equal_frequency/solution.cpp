class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> count;       // num -> frequency
        unordered_map<int, int> freqCount;   // frequency -> count of nums with this frequency
        int maxFreq = 0;
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            
            // ลดความถี่เก่าออกก่อน
            if (count[num] > 0) {
                freqCount[count[num]]--;
                if (freqCount[count[num]] == 0) {
                    freqCount.erase(count[num]);
                }
            }
            
            // เพิ่มความถี่ใหม่
            count[num]++;
            freqCount[count[num]]++;
            
            // อัปเดตความถี่สูงสุด
            maxFreq = max(maxFreq, count[num]);
            
            // ตรวจสอบเงื่อนไขที่ถูกต้อง
            bool isValid = false;
            
            // กรณี 1: ความถี่ทั้งหมดเป็น 1
            if (maxFreq == 1) {
                isValid = true;
            }
            // กรณี 2: มีความถี่แบบเดียว
            else if (freqCount.size() == 1 && freqCount[maxFreq] == 1) {
                isValid = true;
            }
            // กรณี 3: มีความถี่ที่แตกต่างกันสองค่า
            else if (freqCount.size() == 2) {
                auto it = freqCount.begin();
                int freq1 = it->first, count1 = it->second;
                it++;
                int freq2 = it->first, count2 = it->second;
                
                // กรณีความถี่สูงสุดมากกว่าความถี่ต่ำสุดอยู่ 1 และปรากฏเพียงครั้งเดียว
                if (maxFreq - 1 == min(freq1, freq2) && freqCount[maxFreq] == 1) {
                    isValid = true;
                }
                // กรณีมีความถี่ 1 ปรากฏเพียงครั้งเดียว
                // ต้องตรวจก่อนว่ามีไหมแล้วเช็คจำนวน
                // เมื่อใช้ operator[] (เช่น freqCount[1]) กับ map ถ้า key ไม่มีอยู่ จะสร้าง element ใหม่ ด้วยค่า default (0) ซึ่งจะเปลี่ยนแปลง freqCount.size() และทำให้ logic ผิดพลาด
                else if (freqCount.count(1) && freqCount[1] == 1) {
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
};