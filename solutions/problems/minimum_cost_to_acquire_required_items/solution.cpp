class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // ซื้อเฉพาะไอเทมแยก (Type 1 และ Type 2)
        long long a = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        // ซื้อเฉพาะไอเทมรวม (Type 3) ให้ครอบคลุมความต้องการที่มากที่สุด
        long long b = 1LL * costBoth * max(need1, need2);
        
        // ซื้อไอเทมรวม (Type 3) เท่ากับจำนวนที่ต้องการร่วมกันได้พอดี (min(need1, need2)) แล้วซื้อที่เหลือด้วยไอเทมเดี่ยว
        int mn = min(need1, need2);
        long long c = 1LL * costBoth * mn + 1LL * (need1 - mn) * cost1 + 1LL * (need2 - mn) * cost2;
        
        return min({a, b, c});
    }
};