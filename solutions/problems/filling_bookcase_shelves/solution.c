int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelfWidth) {
    // dp[i] = ความสูงรวมขั้นต่ำสำหรับหนังสือเล่มที่ 0 ถึง i-1
    int* dp = (int*)malloc((booksSize + 1) * sizeof(int));
    for (int i = 0; i <= booksSize; i++) {
        dp[i] = 0;
    }
        
    for (int i = 1; i <= booksSize; i++) {
        int width = books[i-1][0];
        int height = books[i-1][1];
            
        // กรณีวางหนังสือเล่มปัจจุบันไว้คนเดียวในชั้นใหม่
        dp[i] = dp[i-1] + height;
            
        // พยายามรวมหนังสือเล่มก่อนหน้านี้มาไว้ในชั้นเดียวกัน
        // ทุกแบบที่เป็นไปได้จนกว่าจะเกินความกว้างของชั้น
        int currentWidth = width;
        int currentMaxHeight = height;

        for (int j = i-1; j > 0; j--) {
            currentWidth += books[j-1][0];
            if (currentWidth > shelfWidth) {
                break;
            }
            if (books[j-1][1] > currentMaxHeight) {
                currentMaxHeight = books[j-1][1];
            }
            // ความสูงจะเท่ากับ dp[j-1] (ชั้นก่อนหน้าทั้งหมด) + currentMaxHeight (ชั้นล่างสุดที่เอาไปวางกับเล่มอื่นๆตั้งแต่ j..i)
            int newHeight = dp[j-1] + currentMaxHeight;
            if (newHeight < dp[i]) {
                dp[i] = newHeight;
            }
        }
    }        
    int result = dp[booksSize];
    free(dp);
    return result;
}