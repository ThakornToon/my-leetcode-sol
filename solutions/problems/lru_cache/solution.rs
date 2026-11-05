use std::collections::{HashMap, VecDeque};

struct LRUCache {
    capacity: usize,
    // map: key -> (value, version)
    map: HashMap<i32, (i32, u64)>,
    // queue: เก็บ (key, version) ของทุกการใช้งาน
    q: VecDeque<(i32, u64)>,
    // ตัวนับเวอร์ชันสะสม
    global_version: u64,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {

    fn new(capacity: i32) -> Self {
        LRUCache {
            capacity: capacity as usize,
            map: HashMap::new(),
            q: VecDeque::new(),
            global_version: 0,
        }
    }

    // เคลียร์ข้อมูลที่หัว Queue
    fn clean_queue(&mut self) {
        // ทำจนกว่าจะเอาออกไม่ได้แล้ว
        while let Some(&(k, v)) = self.q.front() {
            // ดู version ของ key ที่อยู่หน้าสุดใน Queue เทียบกับใน Map ว่่าเป็นค่าเก่าหรือใหม่
            let is_stale = if let Some(entry) = self.map.get(&k) {
                entry.1 != v
            } else {
                true
            };

            // ถ้าเป็น version เก่าให้เอาออก
            if is_stale {
                self.q.pop_front();
            } else {
                break;
            }
        }
    }
    
    fn get(&mut self, key: i32) -> i32 {
        if let Some(entry) = self.map.get_mut(&key) {
            // ถ้าเจอ key นั้นถือว่านำมาใช้ใหม่ ให้เปลี่ยน version ก่อนใส่ไปใหม่
            self.global_version += 1;  // update version
            entry.1 = self.global_version;
            self.q.push_back((key, self.global_version));
            entry.0
        } else {
            -1
        }
    }
    
    fn put(&mut self, key: i32, value: i32) {
        self.global_version += 1;  // update version
        let ver = self.global_version;

        // ถ้ามี key นี้อยู่แล้ว อัปเดตค่าและเวอร์ชันใหม่ได้เลย
        if self.map.contains_key(&key) {
            self.map.insert(key, (value, ver));
            self.q.push_back((key, ver));
            return;
        }

        // ถ้ายังไม่มีและขนาดเต็มแล้ว ต้องเคลียร์และลบตัวเก่าสุดออก
        self.clean_queue();
        while self.map.len() >= self.capacity {
            // ที่หัว Queue จะเก่าสุด
            if let Some((old_k, old_v)) = self.q.pop_front() {
                // ตรวจ version ว่าเป็น version ล่าสุดของ key นั้นไหม
                let should_remove = if let Some(entry) = self.map.get(&old_k) {
                    entry.1 == old_v
                } else {
                    false
                };

                // ถ้าเป็น version ล่าสุดชอง key นั้นให้ลบออกจาก Map
                if should_remove {
                    self.map.remove(&old_k);
                    break;
                }
            } else {
                break;
            }
            self.clean_queue();
        }

        // เพิ่มข้อมูลใหม่เข้าไป
        self.map.insert(key, (value, ver));
        self.q.push_back((key, ver));
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */