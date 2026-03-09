// x XOR x = 0 (ตัวเลขเดียวกัน XOR กันได้ 0)
// x XOR 0 = x (XOR กับ 0 ได้ตัวเดิม)
impl Solution {
    pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = arr.len();
        let mut prefix = vec![0; n + 1];
        
        // คำนวณ prefix XOR
        for i in 0..n {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        // คำนวณผลลัพธ์สำหรับแต่ละ query
        queries
            .iter()
            .map(|q| {
                let left = q[0] as usize;
                let right = q[1] as usize;
                prefix[right + 1] ^ prefix[left]
            })
            .collect()
    }
}