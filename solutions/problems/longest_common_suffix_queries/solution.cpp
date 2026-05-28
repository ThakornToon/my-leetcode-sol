const int MAXNODES = 5e5; // total chars สูงสุด

struct TrieNode {
    int children[26];
    int minLen;
    int index;
};

class Solution {
private:
    TrieNode pool[MAXNODES]; 
    int nodeCount;  // จำนวนที่ใช้จริง

    int newNode() {
        int id = nodeCount++;
        fill(pool[id].children, pool[id].children + 26, -1);  // set children ทั้งหมดเป็น -1
        pool[id].minLen = INT_MAX;  // ความยาวน้อยสุดจาก level นี้
        pool[id].index  = -1;  // index word ความยาวน้อยสุดจาก level นี้
        return id;
    }
    
    void insertWord(const string& word, int idx) {
        int node = 0;  // ปัจจุบัน (root)
        int len = word.length();
        
        // ปรับความยาวที่สั้นที่สุดของ root
        if (len < pool[node].minLen) {
            pool[node].minLen = len;
            pool[node].index  = idx;
        }
        
        // insert จากหลังมาหน้า
        for (int i = len - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            // ถ้ายังไม่มี
            if (pool[node].children[c] == -1) {
                // สร้าง node
                pool[node].children[c] = newNode(); 
            }

            // ไปที่ node ถัดไป
            node = pool[node].children[c];
            
            // เก็บความยาวที่สั้นสุด
            if (len < pool[node].minLen) {
                pool[node].minLen = len;
                pool[node].index  = idx;
            }
        }
    }
    
    int searchWord(const string& word) {
        int node = 0;
        
        // หาที่ต่อเนื่องมากสุด
        for (int i = word.length() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            // ไปต่อไม่ได้แล้ว
            if (pool[node].children[c] == -1) break;

            // ไป node ถัดไป
            node = pool[node].children[c];
        }
        
        // index ของคำที่สั้นสุด
        return pool[node].index;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        nodeCount = 0;
        newNode(); // root = 0
        
        // insert container words
        for (int i = 0; i < wordsContainer.size(); i++) {
            insertWord(wordsContainer[i], i);
        }
        
        // process queries
        vector<int> result;
        for (const string& query : wordsQuery) {
            result.push_back(searchWord(query));
        }
        
        return result;
    }
};