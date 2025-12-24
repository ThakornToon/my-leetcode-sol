class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        // dp[i] = ความสูงรวมขั้นต่ำสำหรับหนังสือเล่มที่ 0 ถึง i-1
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
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
                currentMaxHeight = max(currentMaxHeight, books[j-1][1]);
                // ความสูงจะเท่ากับ dp[j-1] (ชั้นก่อนหน้าทั้งหมด) + currentMaxHeight (ชั้นล่างสุดที่เอาไปวางกับเล่มอื่นๆตั้งแต่ j..i)
                dp[i] = min(dp[i], dp[j-1] + currentMaxHeight);
            }
        }
        
        return dp[n];
    }
};