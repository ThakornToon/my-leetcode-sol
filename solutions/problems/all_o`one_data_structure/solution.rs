use std::collections::{HashMap, BTreeSet};

struct AllOne {
    key_count: HashMap<String, i32>, 

    // เก็บเป็น (frequency, key) ให้ BTreeSet เรียงลำดับตามความถี่ให้อัตโนมัติ
    count_keys: BTreeSet<(i32, String)>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl AllOne {

    fn new() -> Self {
        AllOne {
            key_count: HashMap::new(),
            count_keys: BTreeSet::new(),
        }
    }
    
    fn inc(&mut self, key: String) {
        let count: &mut i32 = self.key_count.entry(key.clone()).or_insert(0);
        if *count > 0 {
            // ลบสถานะเก่าออกจาก BTreeSet ก่อนอัปเดต
            self.count_keys.remove(&(*count, key.clone()));
        }
        *count += 1;
        // ใส่สถานะใหม่เข้าไป
        self.count_keys.insert((*count, key));
    }
    
    fn dec(&mut self, key: String) {
        if let Some(count) = self.key_count.get_mut(&key) {
            self.count_keys.remove(&(*count, key.clone()));
            *count -= 1;
            let c = *count;
            if c == 0 {
                self.key_count.remove(&key);
            } else {
                self.count_keys.insert((c, key));
            }
        }
    }
    
    fn get_max_key(&self) -> String {
        // ตัวสุดท้ายใน BTreeSet จะมีความถี่สูงสุดเสมอ
        self.count_keys.iter().last().map(|(_, k)| k.clone()).unwrap_or_default()
    }
    
    fn get_min_key(&self) -> String {
        // ตัวแรกใน BTreeSet จะมีความถี่ต่ำสุดเสมอ
        self.count_keys.iter().next().map(|(_, k)| k.clone()).unwrap_or_default()
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * let obj = AllOne::new();
 * obj.inc(key);
 * obj.dec(key);
 * let ret_3: String = obj.get_max_key();
 * let ret_4: String = obj.get_min_key();
 */