impl Solution {
    pub fn count_palindromes(s: String) -> i32 {
        let n = s.len();
        const MOD: i64 = 1_000_000_007;
        let s = s.as_bytes();
        
        // Suffix count และ suffix pairs
        let mut rightCount: Vec<i64> = vec![0; 10];
        let mut rightPairs: Vec<Vec<i64>> = vec![vec![0; 10]; 10];
        
        for i in (0..=(n - 1)).rev() {
            let d = (s[i] - b'0') as usize;
            // อัพเดท rightPairs: ทุกตัวเลขที่อยู่ก่อน d (ใน suffix) จะสร้างคู่กับ d
            for x in 0..10 {
                rightPairs[x][d] += rightCount[x]; // d x
            }
            rightCount[d] += 1;
        }
        
        // Prefix count และ prefix pairs
        let mut leftCount: Vec<i64> = vec![0; 10];
        let mut leftPairs: Vec<Vec<i64>> = vec![vec![0; 10]; 10];
        let mut ans = 0;
        
        for k in 0..n {
            // ให้ d เป็น center
            let d = (s[k] - b'0') as usize;
            
            // ลบ d ออกจาก rightCount และ rightPairs
            rightCount[d] -= 1;
            for x in 0..10 {
                rightPairs[x][d] -= rightCount[x];
            }
            
            // นับผลรวมจาก leftPairs และ rightPairs
            for x in 0..10 {
                for y in 0..10 {
                    ans = (ans + leftPairs[x][y] * rightPairs[x][y]) % MOD; // x d center d x
                }
            }
            
            // อัพเดท leftPairs: เพิ่มคู่ใหม่ระหว่าง d กับทุกตัวใน leftCount
            for x in 0..10 {
                leftPairs[x][d] += leftCount[x]; // x d
            }
            leftCount[d] += 1;
        }
        
        return ans as i32;
    }
}