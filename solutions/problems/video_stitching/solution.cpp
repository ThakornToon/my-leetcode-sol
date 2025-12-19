class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // สร้าง array สำหรับเก็บจุดสิ้นสุดสูงสุดสำหรับแต่ละ start
        vector<int> max_end(time + 1, 0);
        
        // เก็บ max_end สำหรับแต่ละ start time
        for (const auto& clip : clips) {
            int start = clip[0];
            int end = clip[1];
            
            if (start <= time) {
                max_end[start] = max(max_end[start], end);
            }
        }
        
        // Greedy
        int current_end = 0;
        int next_end = 0;
        int count = 0;
        
        for (int i = 0; i <= time; i++) {
            // อัปเดต next_end
            if (max_end[i] > next_end) {
                next_end = max_end[i];
            }
            
            // ถึงจุดที่ต้องเลือกคลิปใหม่
            if (i == current_end) {
                if (next_end <= current_end) {
                    return -1;  // ไม่สามารถไปต่อได้
                }
                
                count++;
                current_end = next_end;
                
                if (current_end >= time) {
                    break;
                }
            }
        }
        
        return (current_end >= time) ? count : -1;
    }
};