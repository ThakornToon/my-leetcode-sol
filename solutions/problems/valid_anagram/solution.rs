impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut cnt = vec![0; 26];
        for v in s.chars() {
            cnt[v as usize - 97] += 1;
        }
        for v in t.chars() {
            cnt[v as usize - 97] -= 1;
        }

        for v in cnt {
            if v != 0 {
                return false;
            }
        }
        return true;
    }
}