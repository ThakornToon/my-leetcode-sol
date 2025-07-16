char* reverseStr(char* s, int k) {
    int size = strlen(s);
    for (int i = 0; i < size; i += 2 * k) {
        int left = i;
        int right = (i + k - 1 > size - 1) ? size - 1 : i + k - 1;
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
    return s;
}