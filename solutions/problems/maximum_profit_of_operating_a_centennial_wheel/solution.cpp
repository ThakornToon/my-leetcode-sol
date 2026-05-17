class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxProfit = -1;
        int maxRound = -1;
        int currentProfit = 0;
        int waiting = 0;
        int round = 0;
        int idx = 0;
        int n = customers.size();
        
        // ตราบใดที่ยังมีลูกค้าในคิว หรือยังมีลูกค้ามาถึงในอนาคต
        while (waiting > 0 || idx < n) {
            // ลูกค้ามาถึงรอบนี้
            if (idx < n) {
                waiting += customers[idx];
                idx++;
            }
            
            // ลูกค้าขึ้นรถ (สูงสุด 4 คน)
            int boarding = min(waiting, 4);
            waiting -= boarding;
            
            // คำนวณกำไร
            currentProfit += boarding * boardingCost - runningCost;
            round++;
            
            // ตรวจสอบว่ากำไรสูงสุดหรือไม่
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
                maxRound = round;
            }
        }
        
        return maxProfit > 0 ? maxRound : -1;;
    }
};