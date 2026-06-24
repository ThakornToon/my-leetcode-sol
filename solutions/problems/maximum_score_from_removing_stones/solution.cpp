class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int maxStone = max({a, b, c});  // เลือกกองที่มากสุดจนกว่าจะหมด
        int sumOther = a + b + c - maxStone;  // ดูว่าอีกสองกองที่เหลือจะพอไหม
        
        if (maxStone > sumOther) {  // กองที่มากสุด > อีกสองกองรวมกัน
            return sumOther;
        } else {  // ทั้งสองกองจะมีหิน >= กองที่มากสุด / 2
            return (a + b + c) / 2;
        }
    }
};