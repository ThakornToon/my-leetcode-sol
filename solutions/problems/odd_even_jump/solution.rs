use std::collections::BTreeMap;

impl Solution {
    pub fn odd_even_jumps(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut odd = vec![false; n];    // เก็บว่าเริ่มจาก index i ด้วย odd jump แล้วไปถึงจุดสิ้นสุดได้ไหม
        let mut even = vec![false; n];   // เก็บว่าเริ่มจาก index i ด้วย even jump แล้วไปถึงจุดสิ้นสุดได้ไหม
        odd[n - 1] = true;               // จุดสิ้นสุดไปถึงตัวเองได้เสมอ
        even[n - 1] = true;              // จุดสิ้นสุดไปถึงตัวเองได้เสมอ

        let mut map = BTreeMap::new();   // ใช้เก็บ (value, index) เรียงจากน้อยไปมาก
        let mut result = 1;              // นับผลลัพธ์ (index สุดท้ายนับเป็น 1)
        map.insert(arr[n - 1], n - 1);
        
        
        for i in (0..n-1).rev() {
            // หา next greater or equal (odd jump)
            // map.range(arr[i]..) -> หาค่าที่ >= arr[i] (เรียงจากน้อยไปมาก)
            // .next() -> ได้ค่าที่น้อยที่สุดที่ >= arr[i]
            if let Some((_, &j)) = map.range(arr[i]..).next() {
                odd[i] = even[j]; // odd jump จาก i ไป j, แล้วต้อง even jump จาก j ไปต่อ
            }
            
            // หา next smaller or equal (even jump)
            // map.range(..=arr[i]) -> หาค่าที่ <= arr[i] (เรียงจากน้อยไปมาก)
            // .next_back() -> ได้ค่าที่มากที่สุดที่ <= arr[i]
            if let Some((_, &j)) = map.range(..=arr[i]).next_back() {
                even[i] = odd[j]; // even jump จาก i ไป j, แล้วต้อง odd jump จาก j ไปต่อ
            }
            
            if odd[i] {
                result += 1; // ถ้าเริ่มจาก i ด้วย odd jump แล้วไปถึงจุดสิ้นสุดได้
            }
            
            // ใส่ค่าเข้า map (ถ้ามีค่าเดิมจะถูกแทนที่ด้วย index ที่น้อยกว่า)
            map.insert(arr[i], i);
        }
        
        result
    }
}