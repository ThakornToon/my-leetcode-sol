impl Solution {
    pub fn to_goat_latin(sentence: String) -> String {
        sentence
            .split_whitespace()
            .enumerate()
            .map(|(i, word)| {
                let first_char = word.chars().next().unwrap();
                let new_word = if "aeiouAEIOU".contains(first_char) {
                    format!("{}ma", word)
                } else {
                    format!("{}{}ma", &word[1..], first_char)
                };
                
                format!("{}{}", new_word, "a".repeat(i + 1))
            })
            .collect::<Vec<String>>()
            .join(" ")
    }
}