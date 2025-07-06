int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int tests = minutesToTest / minutesToDie;
    int pigs = 0;
    int sum = 1;
    while (sum < buckets) {
        sum *= (tests + 1);
        pigs += 1;
    }
    return pigs;
}