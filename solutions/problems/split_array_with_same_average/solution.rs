use std::collections::HashSet;

impl Solution {
    pub fn split_array_same_average(nums: Vec<i32>) -> bool {
        let sum: i32 = nums.iter().sum();
        let n = nums.len();
        
        // ตรวจสอบว่าเป็นไปได้ทางคณิตศาสตร์
        // sumA / k = sumB / (n-k) = sum / n
        // เทียบเท่ากับ sumA = k * sum / n
        // k * sum ต้องหารด้วย n ลงตัว
        let mut possible = false;
        for k in 1..=n/2 {
            if k as i32 * sum % n as i32 == 0 {
                possible = true;
                break;
            }
        }
        if !possible {
            return false;
        }

        // set ของค่าที่เป็นไปได้เมื่อเลือก count ตัวในช่วงทางซ้าย
        let left_size = n / 2;
        let mut left_sums: Vec<HashSet<i32>> = vec![HashSet::new(); left_size + 1];
        left_sums[0].insert(0);
        
        for i in 0..left_size {
            for count in (0..=i).rev() {
                for &current_sum in left_sums[count].clone().iter() {
                    left_sums[count + 1].insert(current_sum + nums[i]);
                }
            }
        }

        // set ของค่าที่เป็นไปได้เมื่อเลือก count ตัวในช่วงทางขวา
        let right_size = n - left_size;
        let mut right_sums: Vec<HashSet<i32>> = vec![HashSet::new(); right_size + 1];
        right_sums[0].insert(0);
        
        for i in 0..right_size {
            for count in (0..=i).rev() {
                for &current_sum in right_sums[count].clone().iter() {
                    right_sums[count + 1].insert(current_sum + nums[left_size + i]);
                }
            }
        }

        // ดูทุกความเป็นไปได้เมื่อเลือกมา k ตัว
        for k in 1..=n/2 {
            if k as i32 * sum % n as i32 != 0 {
                continue;
            }
            
            let target_sum = k as i32 * sum / n as i32; // sumA ที่ต้องการ
            
            // จับคู่ซ้ายกับขวา
            let left_k_min = (k as i32 - right_size as i32).max(0) as usize;
            let left_k_max = k.min(left_size);
            
            for left_k in left_k_min..=left_k_max {
                let right_k = k - left_k;
                
                for &left_sum in left_sums[left_k].iter() {
                    let needed_right_sum = target_sum - left_sum;
                    
                    if right_sums[right_k].contains(&needed_right_sum) {
                        return true;
                    }
                }
            }
        }
        
        false
    }
}