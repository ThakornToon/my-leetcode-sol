int calculate(char* s) {
    int n = strlen(s);
    int res = 0, curr = 0, prev = 0;
    char sign = '+';
    for (int i = 0; i < n; i++) {
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n) {
            break;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                curr = (curr) * 10 + (s[i] - '0');
                i++;
            }
            if (sign == '+') {
                res += curr;
                prev = curr;
            } else if (sign == '-') {
                res -= curr;
                prev = -curr;
            } else if (sign == '*') {
                res -= prev;
                res += (prev * curr);
                prev = (prev * curr);
            } else if (sign == '/') {
                res -= prev;
                res += (prev / curr);
                prev = (prev / curr);
            }
            curr = 0;
        }

        if (i == n) {
            break;
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            sign = s[i];
        }
    }
    return res;
}