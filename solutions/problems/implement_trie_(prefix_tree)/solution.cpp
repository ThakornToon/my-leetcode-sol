class Trie {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;
        
        TrieNode() : children(26, nullptr), isEnd(false) {}
    };
    
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        
        for (char c : prefix) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */