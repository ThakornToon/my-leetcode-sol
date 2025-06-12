impl Solution {
    pub fn get_hint(secret: String, guess: String) -> String {
        let secret = secret.as_bytes();
        let guess = guess.as_bytes();
        let mut bulls = 0;
        let mut cows = 0;
        let mut mp: Vec<i32> = vec![0; 10];

        for i in 0..secret.len() {
            if (secret[i] == guess[i]) {
                bulls+=1;
            }
            else {
                mp[(secret[i] - b'0') as usize]+=1;
            }
        }

        for i in 0..guess.len() {
            if (guess[i] != secret[i]) {
                let idx = (guess[i] - b'0') as usize;
                if mp[idx] > 0 {
                    cows += 1;
                    mp[idx] -= 1;
                }
            }
        }
        return format!("{}A{}B", bulls, cows);
    }
}