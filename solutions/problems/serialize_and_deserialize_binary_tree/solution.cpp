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
    // DFS สำหรับ Serialize: ต่อสตริงด้วย to_string และคั่นด้วยคอมมา ','
    // Pre order
    void serializeDFS(TreeNode* root, string& out) {
        if (!root) {
            out += "#,";
            return;
        }
        out += std::to_string(root->val) + ",";
        serializeDFS(root->left, out);
        serializeDFS(root->right, out);
    }

    // DFS สำหรับ Deserialize: เลื่อน index i อ่านข้อมูลตรงจาก string
    TreeNode* deserializeDFS(const std::string& data, int& i) {
        if (i >= data.size()) {
            return nullptr;
        }

        // ตรวจสอบโหนดว่าง
        if (data[i] == '#') {
            i += 2; // ข้าม '#' และ ','
            return nullptr;
        }

        // แปลงตัวเลข (รองรับจำนวนติดลบ)
        int sign = 1;
        if (data[i] == '-') {
            sign = -1;
            i++;
        }

        int val = 0;
        while (i < data.size() && data[i] != ',') {
            val = val * 10 + (data[i] - '0');
            i++;
        }
        val *= sign;
        i++; // ข้ามคอมมา ','

        TreeNode* node = new TreeNode(val);
        node->left = deserializeDFS(data, i);
        node->right = deserializeDFS(data, i);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string out;
        serializeDFS(root, out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        int i = 0;
        return deserializeDFS(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));