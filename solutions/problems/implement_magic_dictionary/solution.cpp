class MagicDictionary {
private:
    unordered_map<int, vector<string>> buckets;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto& word : dictionary) {
            buckets[word.size()].push_back(word);
        }
    }
    
    bool search(string searchWord) {
        int n = searchWord.size();
        if (buckets.find(n) == buckets.end()) return false;

        for (auto& word : buckets[n]) {
            int diff = 0;
            for (int i = 0; i < n; ++i) {
                if (word[i] != searchWord[i]) {
                    diff++;
                }
                if (diff > 1) break; // เกิน 1 ตัว ข้ามไปเช็คคำถัดไปทันที
            }
            if (diff == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */