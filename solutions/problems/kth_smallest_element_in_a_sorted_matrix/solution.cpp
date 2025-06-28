class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        // กำหนด priority queue แบบ min-heap
        // เก็บ tuple ของ (ค่า, แถว, คอลัมน์)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> min_heap;
        
        // เพิ่มสมาชิกตัวแรกของแต่ละแถวลงใน heap
        for (int row = 0; row < n; ++row) {
            min_heap.push({matrix[row][0], row, 0});
        }
        
        // ดึงค่าออกมา k-1 ครั้ง
        for (int i = 0; i < k - 1; ++i) {
            auto [val, row, col] = min_heap.top();
            min_heap.pop();
            
            // ถ้ายังมีสมาชิกในแถวนี้ ให้เพิ่มตัวถัดไป
            if (col + 1 < n) {
                min_heap.push({matrix[row][col + 1], row, col + 1});
            }
        }
        
        // ค่าที่ k จะอยู่ที่หัว heap
        return get<0>(min_heap.top());
    }
};