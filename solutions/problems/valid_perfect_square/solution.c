bool isPerfectSquare(int num) {
    int l = 1;
    int r = num / 2 + 1;
    while (l <= r){
        long long m = l + (r - l) / 2;
        if (m*m == num) {
            return true;
        } else if (m * m < num) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}