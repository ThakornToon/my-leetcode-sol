impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let m = strs.len();
        let n = strs[0].len();
        
        // dp[i] = ความยาวสตริงมากที่สุดที่จบที่ column i ได้
        let mut dp = vec![1; n];
        let mut max_chain = 1;
        
        for i in 0..n {
            for j in 0..i {
                // ตรวจว่า column j มาก่อน column i ได้ไหม
                let mut valid = true;
                // พิจารณาทุกสตริง
                for k in 0..m {
                    if strs[k].as_bytes()[j] > strs[k].as_bytes()[i] {
                        valid = false;
                        break;
                    }
                }
                
                // . . . j i
                if valid {
                    dp[i] = dp[i].max(dp[j] + 1);
                    max_chain = max_chain.max(dp[i]);
                }
            }
        }
        // จำนวนการลบที่น้อยที่สุด
        (n - max_chain) as i32
    }
}