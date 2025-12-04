impl Solution {
    pub fn advantage_count(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let n = nums1.len();
        let mut nums1 = nums1;
        // Sort nums1
        nums1.sort();
        
        // สร้าง indexed nums2 และ sort
        let mut indexed_nums2: Vec<(i32, usize)> = nums2.into_iter()
            .enumerate()
            .map(|(i, val)| (val, i))
            .collect();
        
        indexed_nums2.sort_by_key(|&(val, _)| val);
        
        // สร้างผลลัพธ์
        let mut result = vec![0; n];
        
        // Two pointers
        let mut left = 0;
        let mut right = n - 1;
        
        // ไล่จากค่าที่ใหญ่ที่สุดใน nums2 (จากหลังมาหน้า)
        for i in (0..n).rev() {
            let (value, idx) = indexed_nums2[i];
            
            if nums1[right] > value {
                // ใช้ตัวที่ใหญ่ที่สุด
                result[idx] = nums1[right];
                right -= 1;
            } else {
                // ใช้ตัวที่เล็กที่สุด
                result[idx] = nums1[left];
                left += 1;
            }
        }
        
        result
    }
}