use std::collections::HashMap;

impl Solution {
    // นับจำนวนคู่จาก frequency map
    fn count_pairs_from_freq(freq: &HashMap<i64, i64>, target: i64) -> i64 {
        let mut result = 0;
        let mut keys: Vec<i64> = freq.keys().cloned().collect();
        keys.sort();
        
        for &val in &keys {
            if target % val != 0 {
                continue;
            }
            
            let need = target / val;
            if need < val {
                break; // ป้องกันการนับซ้ำ
            }
            
            let cnt = *freq.get(&val).unwrap_or(&0);
            let need_cnt = *freq.get(&need).unwrap_or(&0);
            
            if need_cnt > 0 {
                if need == val {
                    // กรณี val ซ้ำกัน: C(cnt, 2)
                    result += cnt * (cnt - 1) / 2;
                } else {
                    result += cnt * need_cnt;
                }
            }
        }
        
        result
    }

    pub fn num_triplets(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        // ทำให้ nums2 เป็น array ที่เล็กกว่า (optimization)
        let (smaller, larger) = if nums1.len() <= nums2.len() {
            (nums1, nums2)
        } else {
            (nums2, nums1)
        };
        
        // แปลงเป็น i64 เพื่อป้องกัน overflow
        let smaller: Vec<i64> = smaller.into_iter().map(|x| x as i64).collect();
        let larger: Vec<i64> = larger.into_iter().map(|x| x as i64).collect();
        
        // สร้าง frequency map สำหรับ larger array
        let mut freq_large = HashMap::new();
        for &num in &larger {
            *freq_large.entry(num).or_insert(0) += 1;
        }
        
        let mut result = 0;
        
        // กรณีที่ 1: smaller[i]^2 = larger[j] * larger[k]
        for &num in &smaller {
            let target = num * num;
            result += Self::count_pairs_from_freq(&freq_large, target);
        }
        
        // กรณีที่ 2: larger[j]^2 = smaller[i] * smaller[k]
        // สร้าง frequency map สำหรับ smaller array
        let mut freq_small = HashMap::new();
        for &num in &smaller {
            *freq_small.entry(num).or_insert(0) += 1;
        }
        
        for &num in &larger {
            let target = num * num;
            result += Self::count_pairs_from_freq(&freq_small, target);
        }
        
        result as i32
    }
}