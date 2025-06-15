char* multiply(char* num1, char* num2) {
    if (*num1 == '0' || *num2 == '0') {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    int n = strlen(num1), m = strlen(num2);
    char* ans = (char*)calloc(n + m + 1, sizeof(char));
    for (int i = 0; i < n + m; i++) {
        ans[i] = '0';
    }
    ans[n + m] = '\0';
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + ans[i + j + 1] - '0';
            ans[i + j] += sum / 10;
            ans[i + j + 1] = '0' + sum % 10;
        }
    }
    int start = 0;
    while (ans[start] == '0' && start < n + m - 1) {
        start++;
    }
    char* result = strdup(ans + start);
    free(ans);
    return result;
}