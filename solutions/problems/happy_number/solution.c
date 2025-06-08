int getNext(int n) {
    int res = 0;
    while (n > 0) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}
bool isHappy(int n) {
    int p1 = n;
    int p2 = getNext(n);
    while (p2 != 1 && p1 != p2) {
        p1 = getNext(p1);
        p2 = getNext(getNext(p2));
    }
    if (p2 == 1) {
        return true;
    } else {
        return false;
    }
}