class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2, 0);  // ใช้ n+2 เพื่อความสะดวก
        
        // O(m) สำหรับสร้าง difference array
        for (const auto& booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            
            diff[first] += seats;    // เริ่มเพิ่มที่ first
            diff[last + 1] -= seats; // หยุดเพิ่มที่ last+1
        }
        
        // O(n) สำหรับคำนวณ prefix sum
        vector<int> answer(n);
        answer[0] = diff[1];  // flight 1
        
        for (int i = 2; i <= n; i++) {
            answer[i - 1] = answer[i - 2] + diff[i];
        }
        
        return answer;
    }
};