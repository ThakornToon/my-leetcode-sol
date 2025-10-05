use std::collections::BTreeMap;
impl Solution {
    fn count_of_atoms(formula: String) -> String {
        let mut map = BTreeMap::new();
        let bytes = formula.as_bytes();
        Self::parse(&mut map, &bytes, &mut 0);
        
        let mut result = String::new();
        for (atom, count) in map {
            result.push_str(&atom);
            if count > 1 {
                result.push_str(&count.to_string());
            }
        }
        result
    }

    fn parse(map: &mut BTreeMap<String, i32>, s: &[u8], i: &mut usize) {
        while *i < s.len() && s[*i] != b')' {
            if s[*i] == b'(' {
                *i += 1;
                let mut sub_map = BTreeMap::new();
                Self::parse(&mut sub_map, s, i);
                *i += 1;
                
                let mut mul = 0;
                while *i < s.len() && s[*i].is_ascii_digit() {
                    mul = mul * 10 + (s[*i] - b'0') as i32;
                    *i += 1;
                }
                if mul == 0 { mul = 1; }
                
                for (atom, count) in sub_map {
                    *map.entry(atom).or_insert(0) += count * mul;
                }
            } else {
                let mut atom = String::new();
                if s[*i].is_ascii_uppercase() {
                    atom.push(s[*i] as char);
                    *i += 1;
                    while *i < s.len() && s[*i].is_ascii_lowercase() {
                        atom.push(s[*i] as char);
                        *i += 1;
                    }
                    
                    let mut count = 0;
                    while *i < s.len() && s[*i].is_ascii_digit() {
                        count = count * 10 + (s[*i] - b'0') as i32;
                        *i += 1;
                    }
                    if count == 0 { count = 1; }
                    
                    *map.entry(atom).or_insert(0) += count;
                } else {
                    *i += 1;
                }
            }
        }
    }
}