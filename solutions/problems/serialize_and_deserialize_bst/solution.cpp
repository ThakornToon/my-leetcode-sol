/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    // Pre order
    void serializeDfs(TreeNode* root, string& out) {
        if (!root) return;
        out += to_string(root->val) + " ";
        serializeDfs(root->left, out);
        serializeDfs(root->right, out);
    }

    TreeNode* deserializeDfs(vector<int>& vals, int& idx, int upper_bound) {
        if (idx >= vals.size() || vals[idx] > upper_bound) {
            return nullptr;
        }

        int val = vals[idx++];
        TreeNode* root = new TreeNode(val);

        root->left = deserializeDfs(vals, idx, val);
        root->right = deserializeDfs(vals, idx, upper_bound);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out = "";
        serializeDfs(root, out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vals;
        int n = data.size();
        int i = 0;

        // แยกตัวเลขจากสตริง
        while (i < n) {
            while (i < n && data[i] == ' ') i++;
            if (i >= n) break;

            int sign = 1;
            if (data[i] == '-') {
                sign = -1;
                i++;
            }

            int val = 0;
            while (i < n && data[i] >= '0' && data[i] <= '9') {
                val = val * 10 + (data[i] - '0');
                i++;
            }
            vals.push_back(val * sign);
        }

        int idx = 0;
        return deserializeDfs(vals, idx, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;