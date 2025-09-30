class Solution {
public:
    string solveEquation(string equation) {
        int firstConst = 0;
        int secConst = 0;
        int firstX = 0;
        int secX = 0;

        int sign = 1;
        bool left = true;
        int n = equation.length();
        int i = 0;
        
        while (i < n) {
            int num = 0;
            bool hasNum = false;
            
            // Read numbers
            while (i < n && isdigit(equation[i])) {
                num = num * 10 + (equation[i] - '0');
                i++;
                hasNum = true;
            }

            if (i < n && equation[i] == 'x') {
                if (!hasNum) {
                    num = 1;
                }

                if (left) {
                    firstX += (num * sign);
                } else {
                    secX += (num * sign);
                }
                i++;
                
                if (equation[i] == '-') {
                    sign = -1;
                    i++;
                } else {
                    sign = 1;
                    if (i < n && equation[i] == '=') {
                        left = false;
                        i++;
                    } else if (i < n && equation[i] == '+') {
                        i++;
                    }
                }
            } else if (i < n && equation[i] == '-') {
                if (left) {
                    firstConst += (num * sign);
                } else {
                    secConst += (num * sign);
                }
                sign = -1;
                i++;
            } else {
                if (left) {
                    firstConst += (num * sign);
                } else {
                    secConst += (num * sign);
                }
                  
                if (equation[i] == '+') {
                    sign = 1;
                    i++;
                } else {
                    left = false;
                    sign = 1;
                    i++;
                }
            }
        }

        firstX -= secX;
        secConst -= firstConst;
        
        if (firstX == 0 && secConst == 0) {
            return "Infinite solutions";
        } else if (firstX == 0) {
            return "No solution";
        } else {
            int result = secConst / firstX;
            return "x=" + to_string(result);
        }
    }
};