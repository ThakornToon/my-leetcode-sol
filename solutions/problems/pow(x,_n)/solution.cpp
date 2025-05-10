class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) {
            return 1.0;
        }

        double result = 1.0;
        int64_t n_64 = n;
        if (n_64 < 0) {
            x = 1.0 / x;
            n_64 = -n_64;
        }

        while (n_64 > 0) {
            if (n_64 % 2 == 1) {
                result *= x;
            }
            x *= x;
            n_64 /= 2;
        }

        return result;
    }
};