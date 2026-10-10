impl Solution {
    pub fn min_sum_square_diff(nums1: Vec<i32>, nums2: Vec<i32>, k1: i32, k2: i32) -> i64 {
        let k = (k1 as i64) + (k2 as i64);
        let mut d: Vec<i64> = nums1.iter().zip(nums2.iter())
            .map(|(a, b)| (*a as i64 - *b as i64).abs())
            .collect();
        
        let total_diff: i64 = d.iter().sum();
        if total_diff <= k {
            return 0;
        }
        
        let max_d = *d.iter().max().unwrap();
        
        // Binary Search หาว่าปรับ diff ก้อนบนลงมาทั้งหมดได้มากสุดเท่าไรให้ได้ค่า mid ด้วย k ที่มี
        let mut low = 0;
        let mut high = max_d;
        let mut ans = max_d;
        
        while low <= high {
            let mid = low + (high - low) / 2;
            let ops: i64 = d.iter().map(|&x| if x > mid { x - mid } else { 0 }).sum();  // จำนวน k น้อยสุดที่ต้องใช้ให้ diff ทั้งหมดไม่เกิน mid
            if ops <= k {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // ปรับลดค่าตามค่า ans ที่หาได้
        let mut used_ops = 0;
        for x in d.iter_mut() {
            if *x > ans {
                used_ops += *x - ans;
                *x = ans;
            }
        }
        
        // กระจายโควตาที่เหลือ
        let mut remaining_ops = k - used_ops;
        for x in d.iter_mut() {
            if remaining_ops > 0 && *x == ans {
                *x -= 1;
                remaining_ops -= 1;
            }
        }
        
        // คำนวณผลรวมกำลังสอง
        d.iter().map(|&x| x * x).sum()
    }
}