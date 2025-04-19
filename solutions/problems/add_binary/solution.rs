impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut s = String::from("");
        let mut i:usize = 0;
        let mut boo = 0;
        let ac:usize = a.chars().count();
        let bc:usize = b.chars().count();
        while(i<ac || i<bc){
            match (a.chars().rev().nth(0+i), b.chars().rev().nth(0+i)){
                (Some('1'), Some('1')) => {
                    if(boo==1){
                        s.push('1');
                    }
                    else{
                        s.push('0');
                        boo=1;
                    }
                },
                (Some('0'), Some('0')) => {
                    if(boo==1){
                        s.push('1');
                        boo=0;
                    }
                    else{
                        s.push('0');
                    }
                },
                (Some(n), None) => {
                    if(boo==1){
                        if(n=='1'){
                            s.push('0');
                        }
                        else{
                            s.push('1');
                            boo=0;
                        }
                    }
                    else{
                        s.push(n);
                    }
                },
                (None, Some(n)) => {
                    if(boo==1){
                        if(n=='1'){
                            s.push('0');
                        }
                        else{
                            s.push('1');
                            boo=0;
                        }
                    }
                    else{
                        s.push(n);
                    }
                },
                _ => {
                    if(boo==1){
                        s.push('0');
                    }
                    else{
                        s.push('1');
                    }
                }
            };
            i+=1;
        }
        if(boo==1){
            s.push('1');
        }

        let mut s = s.chars().rev().collect();
        return s;
    }
}