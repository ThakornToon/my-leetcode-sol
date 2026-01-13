class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxY = INT_MIN;
        double minY = INT_MAX;
        
        // หาค่า y ต่ำสุดและสูงสุดที่เป็นไปได้
        for (const auto& square : squares) {
            int y = square[1];
            double side = square[2];
            double top = y + side;  // ขอบบนของสี่เหลี่ยม
            
            maxY = max(maxY, top);
            minY = min(minY, (double)y);  // ขอบล่างของสี่เหลี่ยม
        }
        
        // Binary Search หาค่า y ที่เหมาะสม
        double epsilon = 1e-5;
        
        while (maxY - minY > epsilon) {
            double midY = minY + (maxY - minY) / 2.0;
            double upArea = 0.0;    // พื้นที่เหนือเส้น
            double downArea = 0.0;  // พื้นที่ใต้เส้น
            
            for (const auto& square : squares) {
                int y = square[1];
                double side = square[2];
                double squareTop = y + side;
                
                if (midY >= squareTop) {
                    // เส้นแบ่งอยู่เหนือสี่เหลี่ยมทั้งหมด → ทั้งสี่เหลี่ยมอยู่ใต้เส้น
                    downArea += (side * side);
                } else if (midY <= y) {
                    // เส้นแบ่งอยู่ใต้สี่เหลี่ยมทั้งหมด → ทั้งสี่เหลี่ยมอยู่เหนือเส้น
                    upArea += (side * side);
                } else {
                    // เส้นแบ่งตัดผ่านสี่เหลี่ยม
                    double heightBelow = midY - y;           // ส่วนที่อยู่ใต้เส้น
                    double heightAbove = squareTop - midY;   // ส่วนที่อยู่เหนือเส้น
                    
                    downArea += (heightBelow * side);
                    upArea += (heightAbove * side);
                }
            }
            
            // เปรียบเทียบพื้นที่
            double diff = upArea - downArea;
            
            if (fabs(diff) < epsilon) {
                // พื้นที่เท่ากัน (ใน tolerance)
                // พยายามหา y ที่น้อยที่สุด → เลื่อน maxY ลง
                maxY = midY;
            } else if (diff > 0) {
                // พื้นที่บนมากกว่าล่าง → ต้องยกเส้นแบ่งขึ้น
                minY = midY;
            } else {
                // พื้นที่ล่างมากกว่าบน → ต้องลดเส้นแบ่งลง
                maxY = midY;
            }
        }
        
        return minY;  // หรือ (minY + maxY) / 2.0
    }
};