impl Solution {
    pub fn is_rectangle_overlap(rec1: Vec<i32>, rec2: Vec<i32>) -> bool {
        let no_overlap = 
            rec1[0] >= rec2[2] ||  // rec1 อยู่ขวาสุดของ rec2
            rec1[2] <= rec2[0] ||  // rec1 อยู่ซ้ายสุดของ rec2
            rec1[1] >= rec2[3] ||  // rec1 อยู่บนสุดของ rec2
            rec1[3] <= rec2[1];    // rec1 อยู่ล่างสุดของ rec2
        
        !no_overlap  // ทับกันก็ต่อเมื่อไม่ใช่ "ไม่ทับกัน"
    }
}