class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (n == m) return 1;
        
        if (n > m) swap(n, m);
        
        // ใช้ vector ของ int แทน grid 2D
        // แต่ละ int แทนหนึ่งแถว
        vector<int> rows(n, 0);
        int fullMask = (1 << m) - 1;  // 11111...1 ทั้งหมด m(cols) ตัว
        result = INT_MAX;
        
        dfs(rows, n, m, 0, fullMask);
        return result;
    }

private:
    int result;
    
    // หาตำแหน่งว่างซ้ายบนสุด
    pair<int, int> findEmpty(const vector<int>& rows, int m, int fullMask) {
        for (int i = 0; i < rows.size(); i++) {
            if (rows[i] != fullMask) {
                // หาคอลัมน์ว่างแรกในแถวนี้
                for (int j = 0; j < m; j++) {
                    if (!(rows[i] & (1 << j))) {
                        return {i, j};
                    }
                }
            }
        }
        return {-1, -1};
    }
    
    bool canPlace(const vector<int>& rows, int x, int y, int size) {
        int squareMask = ((1 << size) - 1) << y;
        
        for (int i = 0; i < size; i++) {
            if (rows[x + i] & squareMask) {
                return false;
            }
        }
        return true;
    }
    
    void placeSquare(vector<int>& rows, int x, int y, int size, bool place) {
        int squareMask = ((1 << size) - 1) << y;
        
        if (place) {
            for (int i = 0; i < size; i++) {
                rows[x + i] |= squareMask;
            }
        } else {
            int clearMask = ~squareMask;
            for (int i = 0; i < size; i++) {
                rows[x + i] &= clearMask;
            }
        }
    }
    
    void dfs(vector<int>& rows, int n, int m, int count, int fullMask) {
        if (count >= result) return;
        
        auto [x, y] = findEmpty(rows, m, fullMask);

        // หาช่องว่างไม่เจอแล้ว
        if (x == -1) {
            result = min(result, count);
            return;
        }
        
        // หาขนาดสูงสุด
        int maxSize = min(n - x, m - y);
        
        // ตรวจสอบว่าไม่มีสี่เหลี่ยมขวางทาง
        // ลองจากใหญ่ไปเล็ก
        for (int size = maxSize; size >= 1; size--) {
            if (canPlace(rows, x, y, size)) {
                placeSquare(rows, x, y, size, true);
                dfs(rows, n, m, count + 1, fullMask);
                placeSquare(rows, x, y, size, false);  // backtrack
            }
        }
    }
};