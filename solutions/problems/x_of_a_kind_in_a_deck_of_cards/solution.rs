use std::collections::HashMap;

impl Solution {
    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        // เก็บความถี่ของไพ่แต่ละใบ
        let mut freq = HashMap::new();
        for &card in &deck {
            *freq.entry(card).or_insert(0) += 1;
        }
        
        // หา GCD ของความถี่ทั้งหมด
        let mut g = 0;
        for &count in freq.values() {
            if g == 0 {
                g = count;
            } else {
                g = Self::gcd(g, count);
            }
        }
        
        g >= 2
    }

    fn gcd(a: i32, b: i32) -> i32 {
        let mut a = a;
        let mut b = b;
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }
}