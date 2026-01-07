impl Solution {
    pub fn count_vowel_permutation(n: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        
        // สำหรับ n = 1
        let (mut a, mut e, mut i, mut o, mut u) = (1, 1, 1, 1, 1);
        
        // อัพเดทสำหรับความยาว 2 ถึง n
        for _ in 1..n {
            let (new_a, new_e, new_i, new_o, new_u) = (
                // a ตามด้วย e
                e % MOD,
                // e ตามด้วย a หรือ i
                (a + i) % MOD,
                // i ตามด้วย a, e, o, u (แต่ไม่ i เอง)
                (a + e + o + u) % MOD,
                // o ตามด้วย i หรือ u
                (i + u) % MOD,
                // u ตามด้วย a
                a % MOD,
            );
            
            a = new_a;
            e = new_e;
            i = new_i;
            o = new_o;
            u = new_u;
        }
        
        // รวมผลลัพธ์
        let result = (a + e + i + o + u) % MOD;
        
        result as i32
    }
}