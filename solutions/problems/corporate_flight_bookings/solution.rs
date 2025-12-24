impl Solution {
    pub fn corp_flight_bookings(bookings: Vec<Vec<i32>>, n: i32) -> Vec<i32> {
        let n = n as usize;
        let mut diff = vec![0; n + 1];
        
        // สร้าง difference array
        for booking in bookings {
            let first = booking[0] as usize;
            let last = booking[1] as usize;
            let seats = booking[2];
            
            diff[first - 1] += seats;      // เริ่มที่ first (0-based)
            if last < n {
                diff[last] -= seats;       // หยุดที่ last+1 (0-based)
            }
        }
        
        // คำนวณ prefix sum
        let mut result = vec![0; n];
        result[0] = diff[0];
        for i in 1..n {
            result[i] = result[i - 1] + diff[i];
        }
        
        result
    }
}