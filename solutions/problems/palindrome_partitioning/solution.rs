impl Solution {
    fn check_pa(s: &Vec<char>, start: usize, end: usize)->bool {
        for i in 0..(end - start + 1)/2 {
            if s[start + i] != s[end - i] {
                return false;
            }
        }
        return true;
    }
    fn backtrack(s: &Vec<char>, ans: &mut Vec<Vec<String>>, store: &mut Vec<String>, start: usize) {
        if start == s.len() {
            ans.push(store.clone());
            return;
        }
        for end in start..s.len() {
            if Self::check_pa(s, start, end) {
                let sub: String = s[start..=end].iter().collect();
                store.push(sub);
                Self::backtrack(s, ans, store, end + 1);
                store.pop();
            }
        }
        return;
    }
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let mut ans: Vec<Vec<String>> = Vec::new();
        let s: Vec<char> = s.chars().collect();
        let mut store: Vec<String> = Vec::new();
        Self::backtrack(&s, &mut ans, &mut store, 0);
        return ans;
    }
}