int myAtoi(char* s) {
    bool is_negative = false;
    bool is_pass = true;
    long long num = 0;
    for (int i=0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            if (!is_pass) {
                break;
            }
            continue;
        }
        if (s[i] == '-') {
            if (!is_pass) {
                break;
            }
            is_negative = true;
            is_pass = false;
            continue;
        }
        else if (s[i] == '+') {
            if (!is_pass) {
                break;
            }
            is_pass = false;
            continue;
        }
        if (s[i] >= 48 && s[i] <= 57) {
            is_pass = false;
            num*=10;
            num = num + (s[i] - '0');
            if (-1*num <= INT32_MIN && is_negative) {
                return INT32_MIN;
            }
            else if (num > INT32_MAX) {
                return INT32_MAX;
            }
        }
        else {
            break;
        }
    }
    if (is_negative) {
        return num*-1;
    }
    return num;
}