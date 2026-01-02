class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount = 0;
        int oddCount = 0;
        
        // นับจำนวนชิปที่ตำแหน่งคู่และคี่
        for (int pos : position) {
            if (pos % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        // ย้ายไปตำแหน่งคู่หรือคี่ที่ประหยัดที่สุด
        // ย้ายจากคู่ไปคู่ หรือจากคี่ไปคี่ → cost 0
        // ย้ายจากคู่ไปคี่ หรือจากคี่ไปคู่ → cost 1
        // ดังนั้นเลือกย้ายไปตำแหน่งที่มีชิปมากที่สุด
        return min(evenCount, oddCount);
    }
};