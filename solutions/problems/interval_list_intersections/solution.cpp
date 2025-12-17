class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        
        while (i < firstList.size() && j < secondList.size()) {
            // หา possible intersection
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            
            // ตรวจสอบว่ามี intersection หรือไม่
            if (start <= end) {
                result.push_back({start, end});
            }
            
            // เลื่อน pointer ของ interval ที่สิ้นสุดก่อน
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};