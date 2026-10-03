use std::collections::HashMap;

struct MagicDictionary {
    buckets: HashMap<usize, Vec<String>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MagicDictionary {

    fn new() -> Self {
        Self {
            buckets: HashMap::new(),
        }
    }
    
    fn build_dict(&mut self, dictionary: Vec<String>) {
        for word in dictionary {
            self.buckets.entry(word.len()).or_default().push(word);
        }
    }
    
    fn search(&self, search_word: String) -> bool {
        let n = search_word.len();
        if let Some(words) = self.buckets.get(&n) {
            for word in words {
                let diff = word
                    .bytes()
                    .zip(search_word.bytes())
                    .filter(|(a, b)| a != b)
                    .count();  // เทียบทีละตัวอักษรว่ามีต่างกันกี่ตำแหน่ง
                if diff == 1 {
                    return true;
                }
            }
        }
        false
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * let obj = MagicDictionary::new();
 * obj.build_dict(dictionary);
 * let ret_2: bool = obj.search(searchWord);
 */