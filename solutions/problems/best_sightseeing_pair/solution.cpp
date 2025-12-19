class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();        
        int max_left = values[0] + 0;  // values[i] + i
        int max_score = INT_MIN;
        
        for (int j = 1; j < n; j++) {
            // คำนวณ score สำหรับคู่ (i, j) โดย i เป็นตัวที่ทำให้ values[i] + i สูงสุด
            int current_score = max_left + values[j] - j;
            max_score = max(max_score, current_score);
            
            // อัปเดต max_left สำหรับ j ถัดไป
            max_left = max(max_left, values[j] + j);
        }
        
        return max_score;
    }
};