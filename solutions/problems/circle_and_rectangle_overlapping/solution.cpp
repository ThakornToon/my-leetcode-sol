class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // 1. ศูนย์กลางอยู่ในสี่เหลี่ยม
        if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) {
            return true;
        }
        
        // 2. ตรวจสอบว่าวงกลมแตะขอบหรือมุม
        // ระยะทางจากศูนย์กลางถึงขอบในแนวแกน X
        int closestX = max(x1, min(x2, xCenter));
        // ระยะทางจากศูนย์กลางถึงขอบในแนวแกน Y
        int closestY = max(y1, min(y2, yCenter));
        
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;
        
        return dx * dx + dy * dy <= radius * radius;
    }
};