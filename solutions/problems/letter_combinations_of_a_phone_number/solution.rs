impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        if digits.is_empty(){
            return vec![];
        }
        let phone = vec!["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
        let mut output = Vec::new();

        fn backtrack(store:String ,digits: &str ,phone: &Vec<&str>, output: &mut Vec<String>){
            if digits.is_empty(){
                output.push(store);
                return;
            }
            let ch = phone[digits.chars().nth(0).unwrap() as usize - '0' as usize];
            for c in ch.chars(){
                let n_store = store.clone() + &c.to_string();
                backtrack(n_store, &digits[1..], phone, output);
            }
        }
        backtrack(String::new(), &digits, &phone, &mut output);
        return output;
    }
}