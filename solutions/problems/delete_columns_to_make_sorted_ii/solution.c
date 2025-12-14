int minDeletionSize(char** strs, int strsSize) {
    int n = strlen(strs[0]);
    int deletions = 0;
    
    // สร้าง array สำหรับเก็บสถานะการเรียงลำดับว่า str[i + 1] >= str[i] ไหม
    bool* isSorted = (bool*)calloc(strsSize - 1, sizeof(bool));
    
    for (int col = 0; col < n; col++) {
        bool deleteColumn = false;
        
        // ตรวจสอบว่าต้องลบ column นี้หรือไม่
        for (int row = 1; row < strsSize; row++) {
            if (!isSorted[row - 1] && strs[row][col] < strs[row - 1][col]) {
                deleteColumn = true;
                break;
            }
        }
        
        if (deleteColumn) {
            deletions++;
        } else {
            // อัปเดตสถานะ sorted สำหรับคู่ที่เรียงแล้ว
            for (int row = 1; row < strsSize; row++) {
                if (!isSorted[row - 1] && strs[row][col] > strs[row - 1][col]) {
                    isSorted[row - 1] = true;
                }
            }
        }
    }
    
    free(isSorted);
    return deletions;
}