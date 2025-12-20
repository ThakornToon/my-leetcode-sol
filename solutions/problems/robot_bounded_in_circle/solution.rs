impl Solution {
    pub fn is_robot_bounded(instructions: String) -> bool {
        // Directions: 0 = North, 1 = East, 2 = South, 3 = West
        let dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        
        let mut dir = 0; // Start facing north
        let mut x = 0;
        let mut y = 0;
        
        for c in instructions.chars() {
            match c {
                'G' => {
                    x += dirs[dir].0;
                    y += dirs[dir].1;
                }
                'L' => {
                    dir = (dir + 3) % 4; // Turn left
                }
                'R' => {
                    dir = (dir + 1) % 4; // Turn right
                }
                _ => {}
            }
        }
        
        // ถ้าหุ่นยนต์ไม่ได้หันไปทางเหนือหลังจาก instructions 1 รอบ 
        // ทิศทางจะเปลี่ยนและจะหมุนเป็นวงกลมหรือรูปหลายเหลี่ยม
        // ถ้าหุ่นยนต์ยังหันไปทางเหนือและไม่ได้กลับมาที่ (0,0) จะเดินทางออกไปเรื่อยๆ
        (x == 0 && y == 0) || (dir != 0)
    }
}