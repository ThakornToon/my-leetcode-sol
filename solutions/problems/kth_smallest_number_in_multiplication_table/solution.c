int countLessEqual(int m, int n, int target) {
    int count = 0;
    for (int i = 1; i <= m; i++) {
        // ในแถวที่ i, จำนวน column ที่ i*j ≤ target
        int add = target / i;
        if (add > n) add = n;
        count += add;
    }
    return count;
}

int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        int count = countLessEqual(m, n, mid);
        
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}