class AllOne {
private:
    // แต่ละโหนดคือความถี่ที่ปรากฏและ key ที่มีความถี่ตรงกัน
    struct Node {
        int count;
        unordered_set<string> keys;
        Node(int c) : count(c) {}
    };

    list<Node> freqList;  // เก็บ Node ความถี่ต่างๆไว้เรียงน้อยไปมาก
    unordered_map<string, list<Node>::iterator> keyToNode;  // {key, it ไป ยังโหนดใน list}

public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            // ถ้ายังไม่มีคีย์นี้ ให้เริ่มที่ความถี่ 1
            if (freqList.empty() || freqList.front().count > 1) {
                freqList.push_front(Node(1));
            }
            freqList.front().keys.insert(key);
            keyToNode[key] = freqList.begin();
        } else {
            // ถ้ามีอยู่แล้ว ย้ายไปโหนดความถี่ถัดไป (+1)
            auto currIter = keyToNode[key];
            int nextCount = currIter->count + 1;
            auto nextIter = next(currIter);
            
            // หากไม่มีโหนดความถี่ถัดไปให้สร้างขึ้นมาเพิ่ม
            if (nextIter == freqList.end() || nextIter->count > nextCount) {
                nextIter = freqList.insert(nextIter, Node(nextCount));
            }
            
            nextIter->keys.insert(key);
            keyToNode[key] = nextIter;
            
            currIter->keys.erase(key);
            if (currIter->keys.empty()) {
                freqList.erase(currIter);
            }
        }
    }
    
    void dec(string key) {
        auto currIter = keyToNode[key];
        int count = currIter->count;
        
        if (count == 1) {
            keyToNode.erase(key);
        } else {
            int prevCount = count - 1;
            auto prevIter = (currIter == freqList.begin()) ? freqList.end() : prev(currIter);
            
            // หากไม่มีโหนดให้สร้างมาเพิ่ม
            if (currIter == freqList.begin() || prevIter->count < prevCount) {
                prevIter = freqList.insert(currIter, Node(prevCount));
            }
            
            prevIter->keys.insert(key);
            keyToNode[key] = prevIter;
        }
        
        currIter->keys.erase(key);
        if (currIter->keys.empty()) {
            freqList.erase(currIter);
        }
    }
    
    string getMaxKey() {
        if (freqList.empty()) return "";
        return *(freqList.back().keys.begin());
    }
    
    string getMinKey() {
        if (freqList.empty()) return "";
        return *(freqList.front().keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */