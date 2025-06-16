impl Solution {
    fn is_vowel(a: char) -> bool {
    match a.to_ascii_lowercase() {
        'a' | 'e' | 'i' | 'o' | 'u' => true,
        _ => false,
    }
}
    pub fn reverse_vowels(s: String) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        let mut start = 0;
        let mut end = chars.len() - 1;

        while start < end {
            while start < end && !Self::is_vowel(chars[start]) {
                start += 1;
            }
            
            while start < end && !Self::is_vowel(chars[end]) {
                end -= 1;
            }
            
            if start < end {
                chars.swap(start, end);
                start += 1;
                end -= 1;
            }
        }
        
        let res = chars.into_iter().collect();
        return res;
    }
}