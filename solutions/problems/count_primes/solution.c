int countPrimes(int n) {
    if (n <= 1) {
        return 0;
    }
    int count = 0;
    bool* arr = (bool*)calloc(n ,sizeof(bool)); //0..=(n-1)
    arr[0]=true; //true คือไม่ prime
    arr[1]=true;
    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == true) {
            continue;
        }
        for (int j = i * i; j < n; j += i) {
            arr[j] = true;
        }
    }
    for (int i = 2; i < n; i++) {
        if (!arr[i]) {
            count++;
        }
    }
    free(arr);
    return count;
}