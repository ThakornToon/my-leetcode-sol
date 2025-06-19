class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // เรียงจุดสิ้นสุด น้อยไปมาก
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0;
        int prevEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                // มีการทับซ้อน
                count++;
            } else {
                // ไม่ทับซ้อน
                prevEnd = intervals[i][1];
            }
        }
        
        return count;
    }
};