impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        if num1 == "0" || num2 == "0" {
            return "0".to_string();
        }

        let num1 = num1.as_bytes();
        let num2 = num2.as_bytes();
        let mut ans: Vec<u8> = vec![b'0'; num1.len() + num2.len()];

        for (i, &a) in num1.iter().rev().enumerate() {
            for (j, &b) in num2.iter().rev().enumerate() {
                let product: u8 = (a - b'0') * (b - b'0');
                let sum: u16 = (ans[i + j] - b'0') as u16 + product as u16;
                
                ans[i + j] = (sum % 10) as u8 + b'0';
                ans[i + j + 1] += (sum / 10) as u8;
            }
        }

        let mut start = ans.len() - 1;
        while start > 0 && ans[start] == b'0' {
            start -= 1;
        }
        
        return String::from_utf8(ans.into_iter().take(start+1).rev().collect()).unwrap();
    }
}