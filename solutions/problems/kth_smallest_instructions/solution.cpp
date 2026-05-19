class Solution {
private:
    // คำนวณ Combination C(n, k) แบบปลอดภัยไม่ overflow
    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k;
        
        long long res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (n - k + i) / i;
        }
        return res;
    }
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int rows = destination[0]; // จำนวน V
        int cols = destination[1]; // จำนวน H
        string result;
        
        while (rows > 0 && cols > 0) {
            // จำนวนวิธีถ้าเลือก H ที่ตำแหน่งนี้ = (rows + cols - 1)! / [(rows)!(cols-1)!]
            long long count = comb(rows + cols - 1, rows);
            
            if (k > count) {
                // เลือก V
                result += 'V';
                rows--;
                k -= count;
            } else {
                // เลือก H
                result += 'H';
                cols--;
            }
        }
        
        // เพิ่มตัวอักษรที่เหลือ
        result += string(cols, 'H');
        result += string(rows, 'V');
        
        return result;
    }
};