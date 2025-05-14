impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if (num_rows == 1) {
            return s;
        }
        let mut table: Vec<String> = vec![String::from(""); num_rows as usize];
        let mut row = 0;
        let mut down: bool = true;
        for c in s.chars() {
            table[row as usize].push(c);
            row += if down { 1 } else { -1 };
            down = ( down == (row > 0 && row < num_rows - 1) );
        }                    
        return table.concat();
    }
}