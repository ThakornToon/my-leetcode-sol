class Solution {
private:
    int countLess(int m, int n, int num) {
        int count = 0;
        for (int r = 1; r <= m; r++) {
            count += min(num / r, n);
        }
        return count;
    }
public:
    int findKthNumber(int m, int n, int k) {
        // ทำให้ m เป็นด้านสั้น
        if (m > n) {
            return findKthNumber(n, m, k);
        }

        int left = 0;
        int right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countLess(m, n, mid);

            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};