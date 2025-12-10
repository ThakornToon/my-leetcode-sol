impl Solution {
    pub fn three_sum_multi(arr: Vec<i32>, target: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        use std::collections::HashMap;
        
        let mut count_map = HashMap::new();
        for &num in &arr {
            *count_map.entry(num).or_insert(0) += 1;
        }
        
        let mut unique: Vec<i32> = count_map.keys().cloned().collect();
        unique.sort_unstable();
        let m = arr.len();
        
        let mut result: i64 = 0;
        let m = unique.len();
        
        for i in 0..m {
            let x = unique[i];
            let count_x = *count_map.get(&x).unwrap();
            
            for j in i..m {
                let y = unique[j];
                let count_y = *count_map.get(&y).unwrap();
                
                let z = target - x - y;
                if z < y {
                    continue;
                }
                
                if let Some(&count_z) = count_map.get(&z) {
                    if x == y && y == z {
                        // x = y = z
                        if count_x >= 3 {
                            result += count_x * (count_x - 1) * (count_x - 2) / 6;
                        }
                    } else if x == y && y != z {
                        // x = y ≠ z
                        if count_x >= 2 {
                            result += (count_x * (count_x - 1) / 2) * count_z;
                        }
                    } else if x != y && y == z {
                        // x ≠ y = z
                        if count_y >= 2 {
                            result += count_x * (count_y * (count_y - 1) / 2);
                        }
                    } else {
                        // x < y < z
                        result += count_x * count_y * count_z;
                    }
                }
            }
        }
        
        (result % MOD) as i32
    }
}