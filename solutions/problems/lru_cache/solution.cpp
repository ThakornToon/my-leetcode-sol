class LRUCache {
private:
    int capacity;
    // เก็บคู่ของ {key, value} ใน Doubly Linked List
    list<pair<int, int>> cache_list;
    // เก็บ key และ Iterator ที่ชี้ไปยังตำแหน่งใน list
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        }
        // ย้ายโหนดที่ถูกเรียกใช้งานมาไว้ที่หน้าสุด (Most Recently Used)
        cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
        return cache_map[key]->second;
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            // อัปเดตค่าและย้ายมาไว้หน้าสุด
            cache_map[key]->second = value;
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
            return;
        }
        
        if (cache_list.size() >= capacity) {
            // ลบข้อมูลตัวเก่าสุด (ท้ายสุดของ list) ออกจาก map และ list
            auto last = cache_list.back();
            cache_map.erase(last.first);
            cache_list.pop_back();
        }
        
        // เพิ่มข้อมูลใหม่ไว้หน้าสุด
        cache_list.emplace_front(key, value);
        cache_map[key] = cache_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */