impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut s = String::from("");
        let mut num = num;
        while num!=0{
            if num >= 1000{
                s.push('M');
                num-=1000;
            }
            else if num >= 500{
                if num >= 900{
                    s.push_str("CM");
                    num-=900;
                    continue;
                }
                s.push('D');
                num-=500;
            }
            else if num >= 100{
                if num >= 400{
                    s.push_str("CD");
                    num-=400;
                    continue;
                }
                s.push('C');
                num-=100;
            }
            else if num >= 50{
                if num >= 90{
                    s.push_str("XC");
                    num-=90;
                    continue;
                }
                s.push('L');
                num-=50;
            }
            else if num >= 10{
                if num >= 40{
                    s.push_str("XL");
                    num-=40;
                    continue;
                }
                s.push('X');
                num-=10;
            }
            else if num >= 5{
                if num >= 9{
                    s.push_str("IX");
                    num-=9;
                    continue;
                }
                s.push('V');
                num-=5;
            }
            else if num >= 1{
                if num == 4{
                    s.push_str("IV");
                    num-=4;
                    continue;
                }
                s.push('I');
                num-=1;
            }
        }
        return s;
    }
}