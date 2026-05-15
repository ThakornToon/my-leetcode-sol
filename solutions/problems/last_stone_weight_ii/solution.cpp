class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        // แต่ละบิตแทนว่่าสร้างจำนวนนั้นได้ไหม
        bitset<1501> dp;  // 1501 > total/2
        dp[0] = 1;
        
        for (int stone : stones) {
            // บวกทุกค่าด้วย stones (shift stone ครั้ง) แล้วมา OR
            dp |= (dp << stone);
        }
        
        int target = total / 2;
        for (int i = target; i >= 0; i--) {
            if (dp[i]) {
                return total - 2 * i;
            }
        }
        
        return 0;
    }
};