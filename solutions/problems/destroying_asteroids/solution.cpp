class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // เรียงลำดับ asteroids จากน้อยไปมาก
        sort(asteroids.begin(), asteroids.end());
        
        long long currentMass = mass;
        
        // Greedy: ทำลายก้อนที่เล็กที่สุดก่อนเสมอ
        for (int asteroid : asteroids) {
            if (currentMass >= asteroid) {
                currentMass += asteroid;
            } else {
                return false;  // พบ asteroid ที่ทำลายไม่ได้
            }
        }
        
        return true;  // ทำลายได้ทั้งหมด
    }
};