class Solution {
public:
    bool canAliceWin(int n) {
        int stones = n;
        int remove = 10;
        bool isAliceTurn = true;
        
        while (stones >= remove) {
            stones -= remove;
            remove--;
            isAliceTurn = !isAliceTurn;
        }
        
        // Alice ชนะเมื่อถึงตาของ Bob แต่ Bob เล่นไม่ได้
        return !isAliceTurn;
    }
};