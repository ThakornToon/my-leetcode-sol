class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // เรียงตาม l จากน้อยไปมาก, ถ้า l เท่ากันให้เรียง r จากมากไปน้อย
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) {
                     return a[0] < b[0];
                 }
                 return a[1] > b[1];
             });
        
        int count = 1;  // นับ interval แรก
        vector<int> current = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] > current[1]) {
                // ไม่ถูก cover
                count++;
                current = intervals[i];
            }
            // ถ้า intervals[i][1] <= current[1] → ถูก cover
        }
        
        return count;
    }
};