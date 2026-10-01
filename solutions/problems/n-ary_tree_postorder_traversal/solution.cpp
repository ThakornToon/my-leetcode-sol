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
private:
    void dfs(Node* root, std::vector<int>& result) {
        if (!root) return;

        for (Node* child : root->children) {
            dfs(child, result);
        }
        result.push_back(root->val);
    }

public:
    // Left -> Right -> Root
    vector<int> postorder(Node* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};