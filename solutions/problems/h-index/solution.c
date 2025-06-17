int cmp(const void *a, const void *b) {
    return *((int *)b) - *((int *)a);
}

int hIndex(int* citations, int citationsSize) {
    int idx = 0;
    qsort((void *)citations, citationsSize, sizeof(int), cmp);
    while (idx < citationsSize && idx < citations[idx]) {
        idx++;
    }
    return idx;
}