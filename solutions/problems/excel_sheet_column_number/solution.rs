impl Solution {
    pub fn title_to_number(column_title: String) -> i32 {
        let mut result: i32 = 0;

        for c in column_title.bytes() {
            result *= 26;
            result += (c as i32 - 65) + 1;
        }

        result
    }
}