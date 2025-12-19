class Solution {
public:
    bool divisorGame(int n) {
        /*
        เลขคู่ เลือก 1
        เลขคี่ = คี่ * คี่ เป็นตำแหน่งแพ้
        */
        return n % 2 == 0;
    }
};