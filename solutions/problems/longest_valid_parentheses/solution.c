int longestValidParentheses(char* s) {
    int left = 0, right = 0, maxLen = 0;
    // Left to right pass
    for (int i; i < strlen(s); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            if (maxLen < 2 * right) {
                maxLen = 2 * right;
            }
        } else if (right > left) {
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;
    // Right to left pass
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            if (maxLen < 2 * left) {
                maxLen = 2 * left;
            }
        } else if (left > right) {
            left = 0;
            right = 0;
        }
    }

    return maxLen;
}