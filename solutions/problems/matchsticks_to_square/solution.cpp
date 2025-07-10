class Solution {
private:
    // ลองจับแต่ละไม้ไปไว้ในแต่ละด้าน คิดทุกกรณี
    bool backtrack(const vector<int>& matchsticks, int index, vector<int>& sides, int target) { // index คือตำแหน่งเริ่มพิจารณา
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target;
        }
        
        for (int i = 0; i < 4; i++) { // แต่ละด้าน i
            if (sides[i] + matchsticks[index] > target) continue;
            if (i > 0 && sides[i] == sides[i-1]) continue; //การใส่ไม้ขีด 5 ลงในด้านแรกหรือด้านที่สอง [10, 10, 8, 5] (ทั้งคู่ยาว 10) จะให้ผลลัพธ์เดียวกัน ดังนั้นตรวจสอบเพียงครั้งเดียวก็พอ

            sides[i] += matchsticks[index]; 
            if (backtrack(matchsticks, index + 1, sides, target)) {
                return true;
            }
            sides[i] -= matchsticks[index];
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        int target = total / 4; // ความยาวแต่ละด้าน
        sort(matchsticks.rbegin(), matchsticks.rend()); // ค่ามากไปหาน้อย
        vector<int> sides(4, 0);
        
        return backtrack(matchsticks, 0, sides, target);
    }
};