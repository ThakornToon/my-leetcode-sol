class LFUCache {
private:
    int capacity;
    int minFreq;
    int size;

    // โครงสร้างเก็บบันทึกข้อมูลใน Doubly Linked List
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    // เก็บ it ไปยัง Node ของ key ที่อยู่ใน list
    unordered_map<int, list<Node>::iterator> keyToNode;

    // เก็บ list<Node> ที่มีความถี่การเรียกเดียวกัน
    unordered_map<int, list<Node>> freqToList;

    // เพิ่มความถี่การเรียกของ it ที่ชี้ไปยัง Node นั้นบน list
    void trigger(list<Node>::iterator it, int key) {
        int freq = it->freq;
        int val = it->value;
        
        // ลบออกจาก list ความถี่เดิม
        freqToList[freq].erase(it);
        if (freqToList[freq].empty()) {
            freqToList.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }
        
        // เพิ่มความถี่แล้วย้ายไป list ความถี่ใหม่ (+1)
        freqToList[freq + 1].push_front(Node(key, val, freq + 1));
        keyToNode[key] = freqToList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
        this->size = 0;
    }
    
    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
        auto it = keyToNode[key];
        int val = it->value;
        trigger(it, key);
        return val;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;

        // มี key นี้อยู่แล้ว
        if (keyToNode.find(key) != keyToNode.end()) {
            auto it = keyToNode[key];
            it->value = value;
            trigger(it, key);
            return;
        }

        // เอาออกก่อนเพิ่มค่าใหม่
        if (size >= capacity) {
            // ลบตัวที่อยู่ท้ายสุดของ minFreq list ออก (ความถี่น้อยและ trigger ไปนานสุด)
            auto lastIt = freqToList[minFreq].back();
            keyToNode.erase(lastIt.key);
            freqToList[minFreq].pop_back();
            if (freqToList[minFreq].empty()) {
                freqToList.erase(minFreq);
            }
            size--;
        }

        // เพิ่มข้อมูลใหม่
        minFreq = 1;
        freqToList[1].push_front(Node(key, value, 1));
        keyToNode[key] = freqToList[1].begin();
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */