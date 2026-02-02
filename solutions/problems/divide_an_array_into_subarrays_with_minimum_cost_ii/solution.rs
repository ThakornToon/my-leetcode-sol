use std::collections::BTreeMap;

impl Solution {
    pub fn minimum_cost(nums: Vec<i32>, k: i32, dist: i32) -> i64 {
        let n = nums.len();
        let k = k as usize;
        let dist = dist as usize;
        
        // smaller: เก็บ k-2 elements ที่น้อยที่สุด
        let mut smaller: BTreeMap<i32, i32> = BTreeMap::new();
        let mut smaller_count: usize = 0;
        // larger: เก็บ elements ที่เหลือใน window
        let mut larger: BTreeMap<i32, i32> = BTreeMap::new();
        
        let mut sum_smaller: i64 = 0;
        let mut min_total = i64::MAX;
        
        // เริ่มจาก i1 = 1
        let mut i1 = 1;
        let mut window_end = (i1 + dist).min(n - 1);
        
        // เติม elements เริ่มต้น: จาก i1+1 ถึง window_end
        for j in i1 + 1..=window_end {
            *larger.entry(nums[j]).or_insert(0) += 1;
        }
        
        // ย้าย k-2 elements ที่น้อยที่สุดจาก larger ไป smaller
        while smaller_count < k - 2 && !larger.is_empty() {
            let (&min_val, _) = larger.iter().next().unwrap();
            
            // ลบจาก larger
            Self::remove_from_map(&mut larger, min_val);
            
            // เพิ่มใน smaller
            *smaller.entry(min_val).or_insert(0) += 1;
            sum_smaller += min_val as i64;
            smaller_count += 1;
        }
        
        // บันทึกผลลัพธ์แรก
        if smaller_count == k - 2 {
            min_total = min_total.min(nums[0] as i64 + nums[i1] as i64 + sum_smaller);
        }
        
        // เลื่อน i1 ต่อไป
        for i1 in 2..=n - (k - 1) {
            // 1. ลบ nums[i1] ที่ออกจาก window
            let old_val = nums[i1];
            
            // ลบจาก smaller ก่อน (ถ้ามี)
            if let Some(count) = smaller.get_mut(&old_val) {
                *count -= 1;
                sum_smaller -= old_val as i64;
                smaller_count -= 1;
                if *count == 0 {
                    smaller.remove(&old_val);
                }
            } else if let Some(count) = larger.get_mut(&old_val) {
                // ลบจาก larger
                *count -= 1;
                if *count == 0 {
                    larger.remove(&old_val);
                }
            }
            
            // 2. เพิ่ม element ใหม่ที่ window_end+1 ถ้ามี
            let new_window_end = (i1 + dist).min(n - 1);
            
            // ตรวจสอบว่ามี element ใหม่เพิ่มเข้ามาใน window หรือไม่
            if window_end < new_window_end {
                let new_val = nums[new_window_end];
                
                // ตรวจสอบว่า new_val ควรไป smaller หรือ larger
                // เปรียบเทียบกับค่าที่มากที่สุดใน smaller
                if !smaller.is_empty() {
                    let (&max_in_smaller, _) = smaller.iter().last().unwrap();
                    if (new_val < max_in_smaller) {
                        // เพิ่ม new_val ไป smaller
                        *smaller.entry(new_val).or_insert(0) += 1;
                        sum_smaller += new_val as i64;
                        smaller_count += 1;
                    } else {
                        *larger.entry(new_val).or_insert(0) += 1;
                    }
                } else {
                    *larger.entry(new_val).or_insert(0) += 1;
                }
            }
            
            window_end = new_window_end;
            
            // 3. ปรับ balance ให้ smaller มี k-2 elements
            // ถ้า smaller น้อยเกินไป
            while smaller_count < k - 2 && !larger.is_empty() {
                let (&min_val, _) = larger.iter().next().unwrap();
                
                // ย้ายจาก larger ไป smaller
                Self::remove_from_map(&mut larger, min_val);
                
                *smaller.entry(min_val).or_insert(0) += 1;
                sum_smaller += min_val as i64;
                smaller_count += 1;
            }
            
            // ถ้า smaller มากเกินไป
            while smaller_count > k - 2 {
                let (&max_val, _) = smaller.iter().last().unwrap();
                
                // ย้ายจาก smaller ไป larger
                Self::remove_from_map(&mut smaller, max_val);
                sum_smaller -= max_val as i64;
                smaller_count -= 1;
                
                *larger.entry(max_val).or_insert(0) += 1;
            }
            
            // 4. บันทึกผลลัพธ์
            if smaller_count == k - 2 {
                let current_total = nums[0] as i64 + nums[i1] as i64 + sum_smaller;
                min_total = min_total.min(current_total);
            }
        }
        
        min_total
    }

    fn remove_from_map(map: &mut BTreeMap<i32, i32>, key: i32) {
        if let Some(count) = map.get_mut(&key) {
            *count -= 1;
            if *count == 0 {
                map.remove(&key);
            }
        }
    }
}