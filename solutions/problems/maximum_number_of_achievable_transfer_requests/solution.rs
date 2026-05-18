impl Solution {
    pub fn maximum_requests(n: i32, requests: Vec<Vec<i32>>) -> i32 {
        let m = requests.len();
        let mut result = 0;
        let mut balances = vec![0; n as usize];
        
        // ใช้ closure แทน recursive function
        fn backtrack(
            idx: usize,           // ตำแหน่งปัจจุบันใน requests
            count: i32,           // จำนวน request ที่เลือกไปแล้ว
            n: usize,             // จำนวนอาคาร
            balances: &mut Vec<i32>, // balance ของแต่ละอาคาร
            requests: &Vec<Vec<i32>>, // requests ทั้งหมด
            result: &mut i32,     // ผลลัพธ์ที่ดีที่สุด
        ) {
            let m = requests.len();
            
            // Base case: พิจารณาครบทุก request แล้ว
            if idx == m {
                // ตรวจสอบว่าทุกอาคารมี balance = 0
                let is_valid = balances.iter().all(|&x| x == 0);
                if is_valid {
                    *result = (*result).max(count);
                }
                return;
            }
            
            // ดึงข้อมูล request ปัจจุบัน
            let from = requests[idx][0] as usize;
            let to = requests[idx][1] as usize;
            
            // OPTION 1: เลือก request นี้
            balances[from] -= 1;
            balances[to] += 1;
            backtrack(idx + 1, count + 1, n, balances, requests, result);
            
            // Backtrack: ยกเลิกการเลือก request นี้
            balances[from] += 1;
            balances[to] -= 1;
            
            // OPTION 2: ไม่เลือก request นี้
            backtrack(idx + 1, count, n, balances, requests, result);
        }
        
        backtrack(0, 0, n as usize, &mut balances, &requests, &mut result);
        result
    }
}