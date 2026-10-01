class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
    
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            delete children[i];
        }
    }
};

class Solution {
private:
    void insert(TrieNode* root, string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    string getRoot(TrieNode* root, string& word) {
        TrieNode* curr = root;
        string prefix = "";
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) break;  // ไปต่อไม่ได้และยังไม่จบคำ root
            prefix += c;
            curr = curr->children[idx];
            if (curr->isEnd) return prefix;  // จบคำ root
        }
        return word;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (auto& word : dictionary) {
            insert(root, word);
        }

        string result = "";
        string word = "";

        // วนลูปทีละตัวอักษร แยกคำด้วยช่องว่าง (' ')
        for (size_t i = 0; i <= sentence.length(); ++i) {
            if (i < sentence.length() && sentence[i] != ' ') {
                word += sentence[i];
            } else {
                if (!result.empty()) {
                    result += " ";
                }
                result += getRoot(root, word);
                word = ""; // ล้างค่าเพื่อเตรียมรับคำถัดไป
            }
        }

        delete root;
        return result;
    }
};