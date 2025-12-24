impl Solution {
    pub fn min_height_shelves(books: Vec<Vec<i32>>, shelf_width: i32) -> i32 {
        let n = books.len();
        let mut dp = vec![0; n + 1];
        
        for i in 1..=n {
            let width = books[i-1][0] as i32;
            let height = books[i-1][1] as i32;
            
            // วางหนังสือเล่มนี้ไว้ในชั้นใหม่
            dp[i] = dp[i-1] + height;
            
            let mut current_width = width;
            let mut current_max_height = height;
            
            // พยายามรวมหนังสือก่อนหน้านี้
            for j in (1..i).rev() {
                current_width += books[j-1][0] as i32;
                if current_width > shelf_width {
                    break;
                }
                
                current_max_height = current_max_height.max(books[j-1][1] as i32);
                dp[i] = dp[i].min(dp[j-1] + current_max_height);
            }
        }
        
        dp[n]
    }
}