class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //ในหนึ่งวันมีความเป็นไปได้สามแบบ
        vector<int> hold(n, 0);      //มีหุ้นในมือ
        vector<int> cooldown(n, 0);  //อยู่ในช่วง cooldown
        vector<int> ready(n, 0);     //พร้อมที่จะซื้อ
        
        hold[0] = -prices[0];       //ซื้อหุ้นในวันแรก ให้ติดลบเพราะถือว่าขาดทุนอยู่
        cooldown[0] = INT_MIN;      //เป็นไปไม่ได้ที่จะขายในวันแรก
        ready[0] = 0;               //ไม่ทำอะไรในวันแรก
        
        for (int i = 1; i < n; i++) {
            // ถือหุ้นจากวันก่อนหรือซื้อใหม่จากสถานะ ready
            hold[i] = max(hold[i-1], ready[i-1] - prices[i]);
            
            // ขายหุ้นที่ถืออยู่ (มาจาก hold ของวันก่อน)
            cooldown[i] = hold[i-1] + prices[i];
            
            // พร้อมซื้อ (มาจาก ready ของวันก่อนหรือ cooldown ของวันก่อน)
            ready[i] = max(ready[i-1], cooldown[i-1]);
        }
        
        // คำตอบคือค่าสูงสุดระหว่าง cooldown หรือ ready ในวันสุดท้าย
        return max(cooldown[n-1], ready[n-1]);
    }
};