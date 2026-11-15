/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level;
            
            for (int i = 0; i < level_size; ++i) {
                Node* curr = q.front();
                q.pop();
                current_level.push_back(curr->val);
                
                // นำลูกทุกตัวของโหนดปัจจุบันใส่คิว
                for (Node* child : curr->children) {
                    if (child != nullptr) {
                        q.push(child);
                    }
                }
            }
            result.push_back(current_level);
        }
        
        return result;
    }
};