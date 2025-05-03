impl Solution {
    fn gener(result: &mut Vec<String>, s: &mut String, open: i32, close: i32, n: i32){
        if open==n && close==n{
            result.push(s.clone());
            return;
        }
        if open>close{
            s.push(')');
            Self::gener(result, s, open, close+1, n);
            s.pop();
        }
        if open<n{
            s.push('(');
            Self::gener(result, s, open+1, close, n);
            s.pop();
        }
    }
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut v = Vec::new();
        let mut s = String::new();
        Self::gener(&mut v, &mut s, 0, 0, n);
        return v;
    }
}