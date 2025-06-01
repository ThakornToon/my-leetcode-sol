impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let n = ratings.len();
        let mut sum = n; //เริ่มมาได้คนละหนึ่ง
        let mut i = 1;
        while i < n {
            if ratings[i] == ratings[i - 1] { // 1 3 3 3 2 จะได้ลูกอมเป็น 1 2 1 2 1
                i += 1;
                continue;
            }

            let mut c_increase = 0;
            while i < n && ratings[i] > ratings[i - 1] { //ลำดับเพิ่ม 1 3 4 5 ต้องให้ลูกอม 1 2 3 4
                c_increase += 1;
                sum += c_increase;
                i += 1;
            }

            let mut c_decrease = 0;
            while i < n && ratings[i] < ratings[i - 1] {//ลำดับลด 5 3 2 สมมติคนแรกมีลูกอม 4 จะดูว่ามีน้อยกว่ากี่ตัว กรณีนี้มีสองก็จะได้ลูกอม 2 1
                c_decrease += 1;
                sum += c_decrease;
                i += 1;
            } // สังเกตุว่าที่บวกไปจะเรียงลูกอมเป็น 3 2 1 เราต้องเอาไปเทียบกับกรณีที่มากขึ้นอีกที

            sum -= c_increase.min(c_decrease); //จะได้ลำดับ 1 3 4 5 3 2 ได้ลูกอม 1 2 3 4 2 1 เพราะตรงจุดเปลี่ยนจะเกิดการซ้อนกันต้องลบกรณีที่ได้น้อยออก
        }
        return sum as i32;
    }
}