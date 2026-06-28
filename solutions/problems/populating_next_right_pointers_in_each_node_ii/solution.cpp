/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        
        Node* curr = root;
        
        while (curr != nullptr) {
            Node dummy;
            dummy.next = nullptr;
            Node* last = &dummy;
            
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    last->next = curr->left;
                    last = last->next;
                }
                
                if (curr->right != nullptr) {
                    last->next = curr->right;
                    last = last->next;
                }
                
                curr = curr->next;
            }
            
             Node* nextLevelStart = dummy.next;
            curr = nextLevelStart;
        }
        
        return root;
    }
};