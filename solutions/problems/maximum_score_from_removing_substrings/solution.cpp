class Solution {
private:
    // ฟังก์ชันสำหรับลบ pattern และคำนวณคะแนน
    int removePattern(string& s, char first, char second, int score) {
        string stack;
        int points = 0;
        
        for (char c : s) {
            stack.push_back(c);
            
            // ตรวจสอบว่ามี pattern ที่ต้องการลบหรือไม่
            if (stack.size() >= 2 && stack[stack.size() - 2] == first && stack.back() == second) {
                points += score;
                stack.pop_back(); // ลบ second
                stack.pop_back(); // ลบ first
            }
        }
        
        s = stack; // อัปเดตสตริงที่เหลือ
        return points;
    }
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        
        // ลบ pattern ที่ให้คะแนนสูงกว่าก่อน
        if (x > y) {
            // ลบ "ab" ก่อน (คะแนน x)
            totalScore += removePattern(s, 'a', 'b', x);
            // จากนั้นลบ "ba" ที่เหลือ (คะแนน y)
            totalScore += removePattern(s, 'b', 'a', y);
        } else {
            // ลบ "ba" ก่อน (คะแนน y)
            totalScore += removePattern(s, 'b', 'a', y);
            // จากนั้นลบ "ab" ที่เหลือ (คะแนน x)
            totalScore += removePattern(s, 'a', 'b', x);
        }
        
        return totalScore;

    }
};