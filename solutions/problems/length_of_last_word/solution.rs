impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut count:i32 = 0;
        let mut v:i32 = 0;
        for c in s.chars(){
            if c==' '{
                count=0;
            }
            else{
                count+=1;
                v=count;
            }
        }
        v
    }
}