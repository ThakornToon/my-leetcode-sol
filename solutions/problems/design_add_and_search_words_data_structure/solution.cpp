class WordDictionary {
private:
    struct TrieNode {
        array<TrieNode*, 26> children;
        bool isEnd;
        
        TrieNode() : children{nullptr}, isEnd(false) {}
    };
    
    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int index) {
        if (node == nullptr) return false;
        
        if (index == word.length()) {
            return node->isEnd;
        }
        
        char c = word[index];
        
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (dfs(node->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            int idx = c - 'a';
            return dfs(node->children[idx], word, index + 1);
        }
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */