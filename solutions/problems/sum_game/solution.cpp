class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int half = n / 2;
        
        int leftSum = 0, leftQ = 0;
        int rightSum = 0, rightQ = 0;
        
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') leftQ++;
            else leftSum += num[i] - '0';
        }
        
        for (int i = half; i < n; i++) {
            if (num[i] == '?') rightQ++;
            else rightSum += num[i] - '0';
        }
        
        // มี '?' ทั้งสองฝั่ง
        // แต่ละคู่ของ '?' (L 1 ตัว, R 1 ตัว) จะมี net effect = 0
        // เพราะ Alice เลือกให้ห่างสุดไม่ 9 ให้หมดก็ 0 ให้หมด        
        // Bob จะพยายามใช้ turn ของเขาปรับให้ค่าใกล้ขึ้น

        // เหลือแค่ฝั่งเดียว คนหนึ่งจะปรับให้ห่างมากสุดกับอีกคนปรับให้ห่างน้อยสุด เฉลี่ยกันได้ 9
        int diff = leftSum - rightSum;
        int balance = diff + (leftQ - rightQ) * 9 / 2;
        int totalQ = leftQ + rightQ;
        

        // Bob ชนะเมื่อ balance == 0 และ totalQ เป็นเลขคู่
        // ถ้า totalQ เป็นเลขคี่ Alice ในครั้งสุดท้ายสามารถปรับให้ไม่เท่ากันได้เสมอ
        if (balance == 0 && totalQ % 2 == 0) {
            return false; // Bob ชนะ
        }
        return true; // Alice ชนะ
    }
};