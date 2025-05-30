impl Solution {
    pub fn restore_ip_addresses(s: String) -> Vec<String> {
        let n = s.len();
        let mut ans: Vec<String> = Vec::new();
        if (n > 12) {
            return ans;
        }
        fn check(s: &str) ->bool {
            let n = s.len();
            if (n == 1) {
                return true;
            }
            if (s.chars().nth(0).unwrap() == '0') {
                return false;
            }
            let num: i32 = s.parse().unwrap();
            if (num > 255) {
                return false;
            }
            return true;
        }
        for d1 in 1..=3 {
            for d2 in 1..=3 {
                for d3 in 1..=3 {
                    if d1 + d2 + d3 < n && d1 + d2 + d3 + 3 >= n {
                        let p1 = &s[0..d1];
                        let p2 = &s[d1..(d1 + d2)];
                        let p3 = &s[(d1 + d2)..(d1 + d2 + d3)];
                        let p4 = &s[(d1 + d2 + d3)..];

                        if (check(p1) && check(p2) && check(p3) && check(p4)) {
                            let combined = format!("{}.{}.{}.{}", p1, p2, p3, p4);
                            ans.push(combined);
                        }
                    }
                }
            }
        }
        return ans;
    }
}

/*
There needs to be 4 parts per IP. There are always three dots/four candidates (2.5.5.2.5.5.1.1.1.3.5 is not valid, neither is 1.1.1)

When selecting a candidate, it can't have more than 3 characters (2552.55.111.35 is not valid)

When selecting a candidate, its characters cant be above 255 (25.525.511.135 is not valid because of 525 and 511)

When selecting a candidate, IF the candidate has 2 or more characters, then the first can't be a zero. (1.0.1.023 is not valid as member 023 is size>1 and leads with 0. But 0.0.0.0 is valid as each candidate is size 1)
*/