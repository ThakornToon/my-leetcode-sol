int hIndex(int* citations, int citationsSize) {
    int lo = 0, hi = citationsSize - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (citations[mid] == citationsSize - mid) {
            return citations[mid];
        } else if (citations[mid] < citationsSize - mid) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return citationsSize - lo;
}