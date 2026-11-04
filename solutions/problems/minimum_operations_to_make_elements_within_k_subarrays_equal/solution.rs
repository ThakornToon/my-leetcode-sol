use std::collections::BTreeMap;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, x: i32, k: i32) -> i64 {
        let n = nums.len();
        let x = x as usize;
        let k = k as usize;
        
        // ฟังก์ชันช่วยเพิ่ม/ลดความถี่ใน BTreeMap
        fn add_map(map: &mut BTreeMap<i32, i32>, val: i32, sum: &mut i64, count: &mut usize) {
            *map.entry(val).or_insert(0) += 1;
            *sum += val as i64;
            *count += 1;
        }

        fn remove_map(map: &mut BTreeMap<i32, i32>, val: i32, sum: &mut i64, count: &mut usize) {
            if let Some(cnt) = map.get_mut(&val) {
                *cnt -= 1;
                if *cnt == 0 {
                    map.remove(&val);
                }
            }
            *sum -= val as i64;
            *count -= 1;
        }

        fn get_max(map: &BTreeMap<i32, i32>) -> i32 {
            *map.iter().next_back().unwrap().0
        }

        fn get_min(map: &BTreeMap<i32, i32>) -> i32 {
            *map.iter().next().unwrap().0
        }

        // คำนวณ ops ของทุก window ขนาด x
        let mut min_ops = vec![0; n];
        if n >= x {
            let mut lower: BTreeMap<i32, i32> = BTreeMap::new();
            let mut upper: BTreeMap<i32, i32> = BTreeMap::new();
            let mut lower_sum: i64 = 0;
            let mut upper_sum: i64 = 0;
            let mut lower_count: usize = 0;
            let mut upper_count: usize = 0;
            
            for i in 0..n {
                let val = nums[i];
                
                // ใส่ข้อมูลตัวใหม่
                if lower_count == 0 || val <= get_max(&lower) {
                    add_map(&mut lower, val, &mut lower_sum, &mut lower_count);
                } else {
                    add_map(&mut upper, val, &mut upper_sum, &mut upper_count);
                }
                
                // ตัดตัวเก่าออกเมื่อขนาด window เกิน x
                if i >= x {
                    let out = nums[i - x];
                    if lower.contains_key(&out) {
                        remove_map(&mut lower, out, &mut lower_sum, &mut lower_count);
                    } else {
                        remove_map(&mut upper, out, &mut upper_sum, &mut upper_count);
                    }
                }
                
                // จัดสมดุลขนาดของ lower และ upper
                while lower_count < upper_count {
                    let m = get_min(&upper);
                    remove_map(&mut upper, m, &mut upper_sum, &mut upper_count);
                    add_map(&mut lower, m, &mut lower_sum, &mut lower_count);
                }
                while lower_count - upper_count > 1 {
                    let m = get_max(&lower);
                    remove_map(&mut lower, m, &mut lower_sum, &mut lower_count);
                    add_map(&mut upper, m, &mut upper_sum, &mut upper_count);
                }
                
                // คำนวณ opsเมื่อครบขนาด x
                if i >= x - 1 {
                    let median = get_max(&lower) as i64;
                    let ops = (median * lower_count as i64 - lower_sum) + (upper_sum - median * upper_count as i64);
                    min_ops[i - x + 1] = ops;
                }
            }
        }
        
        // DP Bottom-up หาการเลือก k ช่วงที่ไม่ทับซ้อนกัน
        // dp[i][j] คือค่าใช้จ่ายน้อยที่สุดเมื่อพิจารณาเริ่มที่ index i และเหลือช่วงที่ต้องเลือก j ช่วง
        let mut dp = vec![vec![i64::MAX; k + 1]; n + 1];

        // Base case
        for i in 0..=n {
            dp[i][0] = 0;
        }
        
        for j in 1..=k {
            // ไล่จากหลังสุดขึ้นมา
            for i in (0..=n - j * x).rev() {
                let skip = dp[i + 1][j];  // กรณีไม่เลือก window ที่เริ่มที่ i
                let pick = min_ops[i] + dp[i + x][j - 1];  // กรณีเลือก window ที่เริ่มที่ i
                dp[i][j] = std::cmp::min(skip, pick);
            }
        }
        
        dp[0][k]
    }
}