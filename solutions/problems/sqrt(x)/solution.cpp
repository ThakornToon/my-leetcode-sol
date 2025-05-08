class Solution {
public:
    int mySqrt(int x) {
        if (0<x && x<4){
            return 1;
        }
        int higher = min(46340, x / 2);
        int i = 0;
        while (i<=higher){
            int mid = i + (higher - i) / 2;
            if (mid*mid>x){
                higher = mid-1;
            }
            else if (mid*mid==x){
                return mid;
            }
            else{
                i = mid+1;
            }
        }
        return higher;
    }
};