class Solution {
public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n);
        n--;
        
        int op = 0; // 0: *, 1: /, 2: +, 3: -
        
        while (n > 0) {
            if (op == 0) { // Multiplication
                int top = stk.top();
                stk.pop();
                stk.push(top * n);
            } else if (op == 1) { // Division
                int top = stk.top();
                stk.pop();
                stk.push(top / n);
            } else if (op == 2) { // Addition
                stk.push(n);
            } else { // Subtraction
                stk.push(-n);
            }
            
            op = (op + 1) % 4;
            n--;
        }
        
        // Sum all values in stack
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        
        return sum;
    }
};