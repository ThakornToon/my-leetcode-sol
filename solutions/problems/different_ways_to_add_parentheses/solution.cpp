class Solution {
public:
    int cal(int& num1, int& num2, char& sign) {
        if (sign == '+') {
            return num1 + num2;
        } else if (sign == '-') {
            return num1 - num2;
        } else {
            return num1 * num2;
        }
    }
    vector<int> findall(string& exp, int start, int end) {
        vector<int> all;
        for (int i = start; i < end; i++) {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
                vector<int> left = findall(exp, start, i - 1);
                vector<int> right = findall(exp, i + 1, end);
                for (int& l : left) {
                    for (int& r : right) {
                        all.push_back(cal(l, r, exp[i]));
                    }
                }
            }
        }

        if (all.empty()) {
            int num = 0;
            for (int i = start; i <= end; i++) {
                num = (num * 10) + (exp[i] - '0');
            }
            all.push_back(num);
        }
    
        return all;
    }
    vector<int> diffWaysToCompute(string expression) {
        return findall(expression, 0, expression.size() - 1);
    }
};