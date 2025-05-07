class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int tmp = x;
        long long s = 0;
        while (tmp != 0){
            s = s*10+tmp%10;
            tmp /= 10;
        }
        return x==s;
    }
};