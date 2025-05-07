impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let s:&String = &strs[0];
        let mut ss = String::new();
        let mut min = 0;
        let mut count = 0;
        let mut index: usize = 0;
        for check in &strs[..]{
            if check.len()==0{
                return ss;
            }
            else if check.len()==1{
                min=1;
            }
        }

        for check in &strs[1..]{
            while index<s.len() && index<check.len() {
                if check.chars().nth(index) == s.chars().nth(index){
                    count+=1;
                }
                else{
                    if count<min || min==0  {
                        min = count;
                        break;
                    }
                }
                index+=1;
                
            }
//            println!("min={min},count={count}");
            if count==0{
                return ss;
            }
            if count>0 && min==0{
                min=count;
            }
            count=0;
            index=0;
        }
        if min!=0{
            ss.push_str(&s[..min]);
        }
        return ss;
    }
}