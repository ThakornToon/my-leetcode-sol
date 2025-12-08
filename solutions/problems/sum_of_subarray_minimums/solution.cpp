class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        int n = arr.size();
        stack<int> s;
        
        // left[i] = index ของ element ทางซ้ายที่น้อยกว่า arr[i] อันแรก
        // right[i] = index ของ element ทางขวาที่น้อยกว่าหรือเท่ากับ arr[i] อันแรก
        vector<int> left(n), right(n);
        
        // หาขอบเขตซ้าย
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) { // ขยายทางซ้ายเอาค่าที่เท่ากันมาสร้าง subarray ได้
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        // ล้าง stack
        while (!s.empty()) s.pop();
        
        // หาขอบเขตขวา
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) { // ขยายทางขวาไม่เอาค่าที่เท่ากันมาสร้าง subarray
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        // คำนวณผลรวม
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long count = (long long)(i - left[i]) * (right[i] - i);
            total = (total + (count % MOD) * arr[i]) % MOD;
        }
        
        return (int)total;
    }
};