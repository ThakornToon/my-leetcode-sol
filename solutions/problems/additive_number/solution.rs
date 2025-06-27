impl Solution {
    fn backtrack(num: &Vec<char>, start: usize, store: &mut Vec<u64>) -> bool {
        if start == num.len() {
            return store.len() > 2;
        }

        let mut curr: u64 = 0;
        for i in start..num.len() {
            let digit = num[i].to_digit(10).unwrap() as u64;

            // ตรวจสอบ overflow
            curr = match curr.checked_mul(10).and_then(|v| v.checked_add(digit)) {
                Some(val) => val,
                None => break,
            };

            let size = store.len();
            if size >= 2 {
                let sum = store[size-1] + store[size-2];

                if sum == curr {
                    store.push(curr);
                    if Self::backtrack(num, i + 1, store) {
                        return true;
                    }
                    store.pop();
                } else if sum < curr {
                    break;
                }
            } else {
                store.push(curr);
                if Self::backtrack(num, i + 1, store) {
                    return true;
                }
                store.pop();
            }

            // ตรวจสอบ leading zero
            if i == start && num[i] == '0' {
                break;
            }
        }
        false
    }
    pub fn is_additive_number(num: String) -> bool {
        let num: Vec<char> = num.chars().collect();
        let mut store: Vec<u64> = Vec::new();
        Self::backtrack(&num, 0, &mut store)
    }
}