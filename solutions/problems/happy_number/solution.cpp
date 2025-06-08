class Solution {
public:
    int getNext(int n) {
        int res = 0;
        while (n > 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int p1 = n;
        int p2 = getNext(n);
        while (p2 != 1 && p1 != p2) {
            p1 = getNext(p1);
            p2 = getNext(getNext(p2));
        }
        if (p2 == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};

/*
9 -> 81
99 -> 162
999 -> 242
9999 -> 324
...
9999999999999 -> 1053

1.gets 1
2.gets stuck in a cycle

A->B->F->C->D->E->C->D->....(loop C->D->E)

We have p1 starting at the first and p2 starting at the second. In one loop, p1 moves by 1 and p2 by 2. If it is a happy number, p2 will find 1 first, but if it is a loop, p1 will reach the part of the loop after p2. Each time, it gets closer by one. 
For example, C->D->E->C->D->E->C->D->E->... If p1 starts the loop at the first C and p2 is at the second D of the loop, it will have to wait twice for p1=p2 to ensure the loop.
*/