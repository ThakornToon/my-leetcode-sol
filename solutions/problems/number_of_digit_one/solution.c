int countDigitOne(int n) {
    int count = 0;
    int lower = 0;
    int higher = n;
    long long mul = 1;
    while (higher > 0) {
        int curr = higher % 10;
        higher /= 10;

        if (curr == 0) {
            count += higher * mul;
        } else if (curr > 1) {
            count += (higher + 1) * mul;
        } else if (curr == 1) {
            count += (higher * mul) + (lower + 1);
        }

        lower = lower + curr * mul;
        mul *= 10;
    }
    return count;
}