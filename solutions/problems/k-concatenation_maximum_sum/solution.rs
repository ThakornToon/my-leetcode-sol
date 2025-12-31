impl Solution {
    pub fn k_concatenation_max_sum(arr: Vec<i32>, k: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = arr.len();
        let k = k as i64;
        
        if n == 0 {
            return 0;
        }
        
        // 1. หาผลรวมทั้งหมด
        let total_sum: i64 = arr.iter().map(|&x| x as i64).sum();
        
        // 2. Kadane's algorithm สำหรับ 1 สำเนา
        let (mut max_ending_here, mut max_so_far) = (0i64, 0i64);
        for &num in &arr {
            let num = num as i64;
            max_ending_here = num.max(max_ending_here + num);
            max_so_far = max_so_far.max(max_ending_here);
        }
        
        // 3. ถ้า k == 1
        if k == 1 {
            return (max_so_far % MOD) as i32;
        }
        
        // 4. หา max prefix sum
        let mut max_prefix = 0i64;
        let mut prefix_sum = 0i64;
        for &num in &arr {
            prefix_sum += num as i64;
            max_prefix = max_prefix.max(prefix_sum);
        }
        
        // 5. หา max suffix sum
        let mut max_suffix = 0i64;
        let mut suffix_sum = 0i64;
        for &num in arr.iter().rev() {
            suffix_sum += num as i64;
            max_suffix = max_suffix.max(suffix_sum);
        }
        
        // 6. คำนวณผลลัพธ์
        let mut result = 0i64;
        
        // กรณี 1: ภายใน 1 สำเนา
        result = result.max(max_so_far);
        
        // กรณี 2: คร่อม 2 สำเนา
        result = result.max(max_prefix + max_suffix);
        
        // กรณี 3: ใช้ k สำเนา (ถ้าผลรวมเป็นบวก)
        if total_sum > 0 {
            result = result.max(max_prefix + max_suffix + (k - 2) * total_sum);
        }
        
        (result % MOD) as i32
    }
}