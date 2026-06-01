class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // เรียงลำดับจากมากไปน้อย
        sort(cost.begin(), cost.end(), greater<int>());
        
        int total = 0;
        int n = cost.size();
        
        // จ่ายสำหรับ 2 ชิ้นแรกของทุกๆ 3 ชิ้น
        for (int i = 0; i < n; i++) {
            if (i % 3 != 2) { // ข้ามชิ้นที่ 3, 6, 9, ... (ได้ฟรี)
                total += cost[i];
            }
        }
        
        return total;
    }
};