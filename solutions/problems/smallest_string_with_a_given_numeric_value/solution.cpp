class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 'a');
        k -= n; // หลังจากใส่ 'a' ทุกตัวแล้วเหลือเท่าไหร่
        
        // เติมจากด้านหลัง
        for (int i = n - 1; i >= 0 && k > 0; i--) {
            int add = min(25, k); // เพิ่มได้สูงสุด 25 (z - a)
            result[i] += add;
            k -= add;
        }
        
        return result;
    }
};