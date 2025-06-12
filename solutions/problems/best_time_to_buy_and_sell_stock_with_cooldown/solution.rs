impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {  
        // ในหนึ่งวันมีสามสถานะที่เป็นไปได้      
        let mut hold = -prices[0];    // ซื้อหุ้นในวันแรก เก็บค่ากำไรขาดทุนว่าควรซื้อไหม
        let mut cooldown = i32::MIN;   // เป็นไปไม่ได้ที่จะขายในวันแรก
        let mut ready = 0;            // ไม่ทำอะไรในวันแรก
        
        for i in 1..prices.len() {
            // เก็บค่าสถานะของเมื่อวาน
            let prev_hold = hold;
            let prev_cooldown = cooldown;
            
            // อัพเดทสถานะวันนี้
            hold = prev_hold.max(ready - prices[i]); // ค่าสูงสุดระหว่างถือหุ้นจากวันก่อน หรือซื้อหุ้นใหม่จากสถานะ ready (เมื่อวานไม่ได้ทำอะไร)
            cooldown = prev_hold + prices[i]; // หากขายหุ้นที่ถือไว้จากเมื่อวาน
            ready = ready.max(prev_cooldown); // ค่าสูงสุดระหว่างยังพร้อมอยู่(วันนี้ไม่ทำอะไร) หรือมาจาก cooldown ของวันก่อน(พึ่งขายหุ้นไปเมื่อวาน วันนี้จึงต้องพัก)
        }
        
        return ready.max(cooldown);
    }
}