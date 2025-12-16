impl Solution {
    pub fn pancake_sort(arr: Vec<i32>) -> Vec<i32> {
        let mut arr = arr;
        let mut result = Vec::new();
        let n = arr.len();
        
        // เรียงจากใหญ่ไปเล็ก
        for target in (1..=n).rev() {
            // หาตำแหน่งของ target
            let pos = arr[0..target].iter()
                .position(|&x| x == target as i32)
                .unwrap();
            
            // ถ้าอยู่ในตำแหน่งที่ถูกต้องแล้ว ข้าม
            if pos == target - 1 {
                continue;
            }
            
            // พลิกให้ไปอยู่ตำแหน่งแรก
            if pos != 0 {
                result.push((pos+1) as i32);
                arr[0..(pos+1)].reverse();
            }
            
            // พลิกให้ไปอยู่ตำแหน่งที่ถูกต้อง
            result.push(target as i32);
            arr[0..target].reverse();
        }
        
        result
    }
}