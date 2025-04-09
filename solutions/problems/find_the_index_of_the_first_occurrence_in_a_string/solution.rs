impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        match haystack.find(&needle){
            Some(x)=>return x as i32,
            _=>return -1
        };
    }
}