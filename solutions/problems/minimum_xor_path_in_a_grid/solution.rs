impl Solution {
    pub fn min_cost(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        
        // 1024 bits สามารถแทนด้วยอาร์เรย์ของ u64 จำนวน 16 ตัว (16 * 64 = 1024)
        // แบ่งเป็น 16 ช่อง ช่องหนึ่งเก็บได้ 64 บิต แทน bitset<1024>
        let mut dp = vec![vec![[0u64; 16]; n]; m];
        
        // 'v/64' ดูว่าค่านั้นต้องไปอยู่ในช่องไหน เช่น 67 จะอยู่ในช่องที่ 1 มีค่า 3 (เป็น 00...1000 ขนาด 64 bit)
        let set_bit = |bits: &mut [u64; 16], v: usize| {
            bits[v / 64] |= 1 << (v % 64);
        };
        
        let get_bit = |bits: &[u64; 16], v: usize| -> bool {
            (bits[v / 64] & (1 << (v % 64))) != 0
        };
        
        set_bit(&mut dp[0][0], grid[0][0] as usize);
        
        for i in 0..m {
            for j in 0..n {
                if i == 0 && j == 0 {
                    continue;
                }
                let mut prev = [0u64; 16];
                if i > 0 {
                    for k in 0..16 {
                        prev[k] |= dp[i - 1][j][k];
                    }
                }
                if j > 0 {
                    for k in 0..16 {
                        prev[k] |= dp[i][j - 1][k];
                    }
                }
                
                let val = grid[i][j] as usize;
                for v in 0..1024 {
                    if get_bit(&prev, v) {
                        set_bit(&mut dp[i][j], v ^ val);
                    }
                }
            }
        }
        
        for v in 0..1024 {
            if get_bit(&dp[m - 1][n - 1], v) {
                return v as i32;
            }
        }
        0
    }
}