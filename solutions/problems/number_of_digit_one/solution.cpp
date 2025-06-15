class Solution {
public:
    int countDigitOne(int n) {
        vector<int> vec;
        int higher = n;
        while (n > 0) {
            int num = n % 10;
            n /= 10;
            vec.push_back(num);
        }
        int count = 0;
        int lower = 0;
        long long mul = 1;
        for (int i = 0; i < vec.size(); i++) {
            higher /= 10;

            if (vec[i] == 0) {
                count += higher * mul;
            } else if (vec[i] > 1) {
                count += (higher + 1) * mul; 
            } else if (vec[i] == 1) {
                count += (higher * mul) + (lower + 1);
            }

            lower = lower + vec[i] * mul;
            mul *= 10;
        }        
        return count;
    }
};