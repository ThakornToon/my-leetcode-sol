class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;  // Full word end in this node
        int wordCount;  // Number of words in this subtree
        
        TrieNode() : word(""), wordCount(0) {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;
    vector<string> result;
    vector<vector<char>> board;
    int rows, cols;
    
    void insertWord(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
            current->wordCount++;
        }
        current->word = word;
    }
    
    void dfs(int row, int col, TrieNode* node) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) return;
        
        char c = board[row][col];
        if (c == '#') return;  // วนซ้ำมาที่เดิม
        
        int index = c - 'a'; 
        if (node->children[index] == nullptr || node->children[index]->wordCount == 0) {
            return;
        }
        
        // ไป Node ถัดไป
        node = node->children[index];
        
        // ดูว่ามีคำที่มาจบที่ Node นี้ไหม
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
            node->wordCount--;
        }
        
        board[row][col] = '#';  // dfs ดูมาแล้ว
        
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto& dir : dirs) {
            dfs(row + dir[0], col + dir[1], node);
        }
        
        board[row][col] = c;  // backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        this->rows = board.size();
        this->cols = board[0].size();
        
        root = new TrieNode();
        for (const string& word : words) {
            insertWord(word);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(i, j, root);
            }
        }
        
        return result;
    }
};