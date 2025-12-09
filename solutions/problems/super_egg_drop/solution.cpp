class Solution {
public:
    // 1 move หย่อนได้ 1 ฟอง ถ้าแตกเร็วในรอบท้ายๆต้องทดสอบทีลพชั้น
    int superEggDrop(int k, int n) {
        // dp[moves][eggs] = max floors
        // แต่เราไม่ต้องเก็บทุก moves → ใช้ 1D array
        vector<int> dp(k + 1, 0);  // dp[eggs] for current moves
        // Base case dp[0]=0 ที่ move 0 ทุกอย่างเป็น 0 
        int moves = 0;
        
        while (dp[k] < n) {
            moves++;
            // Update backward
            for (int eggs = k; eggs >= 1; eggs--) {
                dp[eggs] = dp[eggs] + dp[eggs - 1] + 1;
                // dp[eggs-1] คือจาก moves-1 (ยังไม่ถูก update)
                // จำนวนชั้นสูงสุดที่สามารถทดสอบได้ด้วย moves ครั้งและ eggs ฟอง ในตอนนี้ = จำนวนชั้นที่สามารถทดสอบด้วย moves-1 และ eggs + จำนวนชั้นที่สามารถทดสอบด้วย moves-1 และ eggs-1 = ชั้นที่ตรวจสอบได้ถ้าไข่แตก + ชั้นที่ตรวจสอบได้ถ้าไข่ไม่แตก + ชั้นที่ทดลอง
            }
        }
        
        return moves;
    }
};