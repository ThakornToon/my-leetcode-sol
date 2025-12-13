int minDeletionSize(char** strs, int strsSize) {
    int n = strlen(strs[0]);  // จำนวน columns
    int deletions = 0;
    
    // ตรวจสอบแต่ละ column
    for (int col = 0; col < n; col++) {
        // ตรวจสอบว่า column นี้เรียงลำดับหรือไม่
        for (int row = 1; row < strsSize; row++) {
            if (strs[row][col] < strs[row - 1][col]) {
                deletions++;
                break;
            }
        }
    }
    
    return deletions;
}