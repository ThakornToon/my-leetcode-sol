class Solution {
public:
    unordered_map<int, int> memo;

    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        if (n % 2 == 0) {
            memo[n] = 1 + integerReplacement(n / 2);
        } else {
            // เปรียบเทียบระหว่าง n+1 และ n-1
            memo[n] = 2 + min(integerReplacement(n / 2),
                              integerReplacement(n / 2 + 1));
        }

        return memo[n];
    }
};