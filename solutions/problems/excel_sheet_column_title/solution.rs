impl Solution {
    pub fn convert_to_title(column_number: i32) -> String {
        let mut column_number = column_number;
        let mut s = String::new();
        while column_number > 0 { //BYC -> เหมือนการแปลงเลขฐานสิบกับยี่สิบหก 3+(26*25)+(26*26*2)
            column_number-=1; //ลดค่าเพื่อให้ A=0, B=1, ..., Z=25
            s.insert(0, ((column_number % 26) as u8 + b'A') as char);
            column_number /= 26;
        }
        return s;
    }
}