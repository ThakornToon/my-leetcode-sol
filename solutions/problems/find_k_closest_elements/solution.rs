impl Solution {
    pub fn find_closest_elements(arr: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
        let k = k as usize;
        let mut left = 0;
        let mut right = arr.len() - k;
        
        while left < right {
            // ตำแหน่งเริ่มต้น
            let mid = left + (right - left) / 2;
            // เปรียบเทียบ สองช่วงที่อาจเป็นคำตอบ:
        //  ช่วง A: เริ่มที่ mid → arr[mid] ถึง arr[mid + k - 1]
        //ช่วง B: เริ่มที่ mid + 1 → arr[mid + 1] ถึง arr[mid + k]
        //ทั้งสองช่วงมี k-1 ตัวที่ซ้อนกัน ต่างกันแค่ตัวแรกและตัวสุดท้าย
            if x - arr[mid] > arr[mid + k] - x {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        arr[left..left + k].to_vec()
    }
}