impl Solution {
    pub fn maximum69_number (num: i32) -> i32 {
        let mut s = num.to_string().into_bytes();
        for c in &mut s {
            if *c == b'6' {
                *c = b'9';
                break;
            }
        }
        String::from_utf8(s).unwrap().parse().unwrap()
    }
}