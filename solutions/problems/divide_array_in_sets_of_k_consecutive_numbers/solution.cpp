class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        
        map<int, int> count;  // ใช้ map เพื่อเรียงลำดับอัตโนมัติ
        
        // นับความถี่
        for (int card : nums) {
            count[card]++;
        }
        
        while (!count.empty()) {
            // หาไพ่ใบแรก (ค่าน้อยสุด) ที่ยังเหลืออยู่
            int firstCard = count.begin()->first;
            
            // พยายามสร้างกลุ่มขนาด groupSize
            for (int i = 0; i < k; i++) {
                int currentCard = firstCard + i;
                
                // ถ้าไม่มีไพ่ใบนี้ → false
                if (count[currentCard] == 0) {
                    return false;
                }
                
                // ใช้ไพ่ใบนี้
                count[currentCard]--;
                
                // ถ้าใช้หมดแล้ว ลบออกจาก map
                if (count[currentCard] == 0) {
                    count.erase(currentCard);
                }
            }
        }
        
        return true;
    }
};