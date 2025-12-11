impl Solution {
    pub fn knight_dialer(n: i32) -> i32 {
        if n == 1 {
            return 10;
        }
        
        const MOD: i64 = 1_000_000_007;
        const SIZE: usize = 10;
        
        // Transition matrix 10 * 10
        let mut m = [[0i64; SIZE]; SIZE];
        
        // move ไปไหนได้บ้าง
        let moves: Vec<Vec<usize>> = vec![
            vec![4, 6],
            vec![6, 8],
            vec![7, 9],
            vec![4, 8],
            vec![0, 3, 9],
            vec![],
            vec![0, 1, 7],
            vec![2, 6],
            vec![1, 3],
            vec![2, 4],
        ];
        
        for (from, to_list) in moves.iter().enumerate() {
            for &to in to_list {
                m[to][from] = 1; // บันทึกใน Transition matrix ว่าสามารถ move จากไหนไปไหนได้บ้าง
            }
        }

        /*
               0 1 2 3 4 5 6 7 8 9  ← from
            0 [0 0 0 0 1 0 1 0 0 0]
            1 [0 0 0 0 0 0 1 0 1 0]  
            2 [0 0 0 0 0 0 0 1 0 1]
            3 [0 0 0 0 1 0 0 0 1 0]
            4 [1 0 0 1 0 0 0 0 0 1]
            5 [0 0 0 0 0 0 0 0 0 0]
            6 [1 1 0 0 0 0 0 1 0 0]
            7 [0 0 1 0 0 0 1 0 0 0]
            8 [0 1 0 1 0 0 0 0 0 0]
            9 [0 0 1 0 1 0 0 0 0 0]
            ↑
            to
        */

        /* สามารถหารูปแบบทั้งหมดจาก M^(n-1)
            M^2[i][j] = จำนวนวิธีจาก j ไป i ใน 2 moves
            M[i][k] = 1 ถ้า k → i ได้
            M[k][j] = 1 ถ้า j → k ได้
            M[i][k] × M[k][j] = 1 ถ้า j → k → i ได้
            M^2[i][j] = Σₖ M[i][k] × M[k][j]
        */
        let result = Self::matrix_power(&m, n as usize - 1);
        
        // รวมผลลัพธ์
        let mut total = 0i64;
        for i in 0..SIZE {
            for j in 0..SIZE {
                total = (total + result[i][j]) % MOD;
            }
        }
        
        total as i32
    }

    fn matrix_multiply(a: &[[i64; 10]; 10], b: &[[i64; 10]; 10]) -> [[i64; 10]; 10] {
        const MOD: i64 = 1_000_000_007;
        let mut result = [[0i64; 10]; 10];
        
        for i in 0..10 {
            for j in 0..10 {
                let mut sum = 0i64;
                for k in 0..10 {
                    sum = (sum + a[i][k] * b[k][j]) % MOD;
                }
                result[i][j] = sum;
            }
        }
        
        result
    }

    fn matrix_power(m: &[[i64; 10]; 10], mut exp: usize) -> [[i64; 10]; 10] {
        let mut result = [[0i64; 10]; 10];
        let mut base = *m;
        
        // Identity matrix แนวเส้นทแยงมุมเป็น 1
        for i in 0..10 {
            result[i][i] = 1;
        }

        // exp = 13 (binary: 1101 = 2^3 + 2^2 + 2^0) -> M^exp = I * M * M^4 * M^8
        while exp > 0 {
            if exp & 1 == 1 {
                result = Self::matrix_multiply(&result, &base);
            }
            base = Self::matrix_multiply(&base, &base);
            exp >>= 1;
        }
        
        result
    }
}