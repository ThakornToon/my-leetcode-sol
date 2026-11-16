use std::collections::{HashMap, BTreeSet};

struct LFUCache {
    capacity: usize,
    min_freq: usize,
    key_to_val: HashMap<i32, (i32, usize)>, // key -> (val, freq)
    freq_to_keys: HashMap<usize, BTreeSet<(usize, i32)>>, // freq -> set of (timestamp, key) เรียงตามเวลาที่มีการเรียกจากน้อยไปมาก
    timestamp: usize,  // เวลาปัจจุบัน
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LFUCache {

    fn new(capacity: i32) -> Self {
        LFUCache {
            capacity: capacity as usize,
            min_freq: 0,
            key_to_val: HashMap::new(),
            freq_to_keys: HashMap::new(),
            timestamp: 0,
        }
    }
    
    fn get(&mut self, key: i32) -> i32 {
        if let Some(&(val, freq)) = self.key_to_val.get(&key) {
            self.trigger(key, val, freq);
            val
        } else {
            -1
        }
    }
    
    fn put(&mut self, key: i32, value: i32) {
        // มี key นั้นอยู่แล้ว
        if let Some(&(old_val, freq)) = self.key_to_val.get(&key) {
            self.trigger(key, value, freq);
            return;
        }

        // ลบ key ความถี่น้อยสุดและเก่าสุด
        if self.key_to_val.len() >= self.capacity {
            // ลบตัวที่มี freq น้อยที่สุดและเก่าที่สุดออก (อยู่หน้าสุดของ BTreeSet)
            if let Some(set) = self.freq_to_keys.get_mut(&self.min_freq) {
                if let Some(&(ts, k)) = set.iter().next() {
                    set.remove(&(ts, k));
                    self.key_to_val.remove(&k);
                }
            }
        }

        self.timestamp += 1;
        self.key_to_val.insert(key, (value, 1));
        self.freq_to_keys.entry(1).or_insert_with(BTreeSet::new).insert((self.timestamp, key));
        self.min_freq = 1;
    }

    fn trigger(&mut self, key: i32, val: i32, freq: usize) {
        self.timestamp += 1;
        
        // เอา key ออกจาก freq เดิม
        if let Some(set) = self.freq_to_keys.get_mut(&freq) {
            // ค้นหาและลบ timestamp เก่าของ key นี้ออก
            let ts_to_remove: Option<(usize, i32)> = set.iter().find(|&&(_, k)| k == key).cloned();

            if let Some(ts_k) = ts_to_remove {
                set.remove(&ts_k);
            }

            if set.is_empty() {
                self.freq_to_keys.remove(&freq);
                if self.min_freq == freq {
                    self.min_freq += 1;
                }
            }
        }

        // ใส่เข้าไปใน freq + 1
        self.key_to_val.insert(key, (val, freq + 1));
        self.freq_to_keys.entry(freq + 1).or_insert_with(BTreeSet::new).insert((self.timestamp, key));
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * let obj = LFUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */