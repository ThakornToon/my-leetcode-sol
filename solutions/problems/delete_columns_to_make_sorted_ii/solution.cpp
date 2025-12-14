class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();        
        int n = strs[0].size();
        int deletions = 0;
        
        // สร้าง array สำหรับเก็บสถานะการเรียงลำดับระหว่าง i กับ i + 1
        vector<bool> isSorted(m - 1, false);
        
        for (int col = 0; col < n; col++) {
            bool deleteColumn = false;
            
            // ตรวจสอบว่าต้องลบ column นี้หรือไม่
            for (int row = 1; row < m; row++) {
                if (!isSorted[row - 1] && strs[row][col] < strs[row - 1][col]) {
                    deleteColumn = true;
                    break;
                }
            }
            
            if (deleteColumn) {
                deletions++;
            } else {
                // อัปเดตสถานะ sorted สำหรับคู่ที่เรียงแล้ว
                for (int row = 1; row < m; row++) {
                    if (!isSorted[row - 1] && strs[row][col] > strs[row - 1][col]) {
                        isSorted[row - 1] = true;
                    }
                }
            }
        }
        
        return deletions;
    }
};