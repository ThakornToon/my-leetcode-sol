impl Solution {
    pub fn num_rescue_boats(people: Vec<i32>, limit: i32) -> i32 {
        let mut people = people;
        people.sort();  // sort น้ำหนักจากน้อยไปมาก
        
        let mut left: usize = 0;
        let mut right: usize = people.len() - 1;
        let mut boats = 0;
        
        while left <= right {
            // ถ้าสามารถใส่คนเบา+คนหนักได้ด้วยกัน
            if people[left] + people[right] <= limit {
                left += 1;   // คนเบาขึ้นเรือ
            } 
            boats += 1;
            if right == 0 {
                break;
            }
            right -= 1; // คนหนักขึ้นเรือ
        }
        
        boats
    }
}