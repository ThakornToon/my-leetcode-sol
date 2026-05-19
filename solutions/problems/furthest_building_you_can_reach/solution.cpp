class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // min-heap เรียงน้อยไปมากสำหรับเก็บความต่างที่ใช้ ladder
        priority_queue<int, vector<int>, greater<int>> ladderUsed;
        
        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff <= 0) continue; // ลงหรือเท่า ไม่ต้องใช้ทรัพยากร
            
            // ใช้ ladder ก่อน
            ladderUsed.push(diff);
            
            // ถ้าใช้ ladder เกินจำนวน ให้เอาความต่างน้อยที่สุดมาใช้ bricks แทน
            if (ladderUsed.size() > ladders) {
                bricks -= ladderUsed.top();
                ladderUsed.pop();
            }
            
            // ถ้า bricks ติดลบ แสดงว่าไปต่อไม่ได้
            if (bricks < 0) {
                return i;
            }
        }
        
        // ไปถึงอาคารสุดท้าย
        return heights.size() - 1;

    }
};