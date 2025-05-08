char* addBinary(char* a, char* b) {
    int carry = 0;
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int sizeOut = 0;
    if (i>j) {
        sizeOut = i+2; //strlen(a)+1
    }
    else {
        sizeOut = j+2; //strlen(b)+1
    }
    char *res = (char *)malloc(sizeOut + 1);
    res[sizeOut] = '\0';
    while (i >= 0 || j >= 0 || carry) {
        if (i>=0) {
            carry += (a[i]-'0');
            i--;
        }
        if (j>=0) {
            carry += (b[j]-'0');
            j--;
        }
        res[--sizeOut] = (carry % 2 + '0');
        carry /= 2;
    }
    return res+sizeOut; //shift pointer: 10+1 = 11\0 frist sizeOut=3, res[3]='\0'(size=4), last sizeOut=1, return res[1..=3]
}