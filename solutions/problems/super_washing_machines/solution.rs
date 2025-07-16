impl Solution {
    pub fn find_min_moves(machines: Vec<i32>) -> i32 {
        let total: i32 = machines.iter().sum();
        let n = machines.len() as i32;
        if total % n != 0 {
            return -1;
        }
        
        let target = total / n;
        let mut result = 0;
        let mut sum = 0;
        
        for &num in &machines {
            let diff = num - target; // จำนวนเสื้อผ้าขั้นต่ำที่เครื่องนี้ต้องส่งออก
            sum += diff; // ดูว่าเครื่องนี้จะต้องได้รับ(-)หรือส่งออก(+)ผ้ากี่ครั้ง เพื่อรับจากทางขวาแล้วค่อยส่งไปทางซ้าย(-) หรือ รับจากทางซ้ายแล้วค่อยส่งไปทางขวา(+)
            result = result.max(diff.max(sum.abs()));
        }
            
        return result;
    }
}