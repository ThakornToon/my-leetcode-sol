impl Solution {
    pub fn die_simulator(n: i32, roll_max: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        // dp[face][consecutive] = current face with consecutive count
        let mut dp = [[0; 16]; 6];
        
        // Initialize for length 1
        for face in 0..6 {
            dp[face][1] = 1;
        }
        
        // For lengths 2 to n
        for _ in 2..=n {
            let mut new_dp = [[0; 16]; 6];
            
            // Calculate total from previous dp and sum for each face
            let mut total = 0i64;
            let mut sum_face = [0i64; 6];
            
            // Calculate sums
            for f in 0..6 {
                let mut face_sum = 0i64;
                
                for c in 1..=(roll_max[f] as usize) {
                    face_sum = (face_sum + dp[f][c]) % MOD;
                }
                
                sum_face[f] = face_sum;
                total = (total + face_sum) % MOD;
            }
            
            // Update DP
            for newf in 0..6 {
                // Case 1: Change to new face 'newf'
                // Comes from all other faces: total - sum_face[newf]
                new_dp[newf][1] = (total - sum_face[newf] + MOD) % MOD;
                
                // Case 2: Continue with same face
                for c in 2..=(roll_max[newf] as usize) {
                    new_dp[newf][c] = dp[newf][c - 1];
                }
            }
            
            // Copy new_dp to dp
            dp = new_dp;
        }
        
        // Sum all results for length n
        let mut result = 0i64;
        for f in 0..6 {
            for c in 1..=(roll_max[f] as usize) {
                result = (result + dp[f][c]) % MOD;
            }
        }
        
        result as i32
    }
}