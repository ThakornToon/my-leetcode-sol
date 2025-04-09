impl Solution {
    pub fn is_valid(s: String) -> bool {
        let i=0;
        let mut v: Vec<char> = Vec::new();
        for ch in s.chars(){
            let c = match ch{
                '(' => '1',
                ')' => '2',
                '[' => '4',
                ']' => '5',
                '{' => '7',
                '}' => '8',
                _ => '9'
            };
            let nc = (c as u8 - 1) as char;
            if &nc ==v.last().unwrap_or(&' '){
                v.pop();
            }
            else{
                v.push(c);
                if v.len()>s.len()/2{
                    break;
                }
            }
//            println!("{:?}",&v);
        }
        if v.is_empty(){
            return true;
        }
        else{
            return false;
        }
    }
}