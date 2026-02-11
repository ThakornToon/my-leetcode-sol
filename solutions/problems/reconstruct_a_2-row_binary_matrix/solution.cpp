class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<int> row1(n, 0), row2(n, 0);
        
        // ใส่ colsum=2 ก่อน
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                if (upper <= 0 || lower <= 0) return {};
                row1[i] = 1;
                row2[i] = 1;
                upper--;
                lower--;
            }
        }
        
        // ใส่ colsum=1
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    row1[i] = 1;
                    upper--;
                } else if (lower > 0) {
                    row2[i] = 1;
                    lower--;
                } else {
                    return {};
                }
            }
        }
        
        // ตรวจสอบว่าจัดสรรครบหรือไม่
        if (upper != 0 || lower != 0) return {};
        
        // ตรวจสอบ colsum
        for (int i = 0; i < n; i++) {
            if (row1[i] + row2[i] != colsum[i]) {
                return {};
            }
        }
        
        return {row1, row2};
    }
};