impl Solution {
    pub fn number_to_words(num: i32) -> String {
        if num == 0 {
            return String::from("Zero");
        }

        fn helper(num: usize) -> String {
            const tens: [&str; 10] = [
                "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", 
                "Sixty", "Seventy", "Eighty", "Ninety",
            ];
            const numbers: [&str; 20] = [
                "", "One", "Two", "Three",
                "Four", "Five", "Six", "Seven",
                "Eight", "Nine", "Ten", "Eleven",
                "Twelve", "Thirteen", "Fourteen", "Fifteen",
                "Sixteen", "Seventeen", "Eighteen", "Nineteen",
            ];
            let mut s = String::new();
            match num {
                n if n < 20 => {
                    s.push_str(numbers[n]);
                },
                n if n < 100 => {
                    s.push_str(tens[n/10]);
                    s.push_str(" ");
                    s.push_str(numbers[n % 10]);
                },
                n if n < 1000 => {
                    s.push_str(numbers[n/100]);
                    s.push_str(" Hundred ");
                    s.push_str(&helper(n % 100));
                },
                n if n < 1000000 => {
                    s.push_str(&helper(n / 1000));
                    s.push_str(" Thousand ");
                    s.push_str(&helper(n % 1000));
                },
                n if n < 1000000000 => {
                    s.push_str(&helper(n / 1000000));
                    s.push_str(" Million ");
                    s.push_str(&helper(n % 1000000));
                },
                _ => {
                    s.push_str(&helper(num / 1000000000));
                    s.push_str(" Billion ");
                    s.push_str(&helper(num % 1000000000));
                }
            }
            s.trim().to_string() //trim() ลบช่องว่างส่วนเกินที่เกิดขึ้นที่หัวหรือท้ายสตริง แล้วแปลงจาก string slice (&str) ที่ได้จาก trim() กลับเป็น String
        }


        helper(num as usize)
    }
}