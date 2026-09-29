/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* next = curr->next;
                Node* child_tail = curr->child;

                // หาโหนดท้ายสุดของกิ่งลูก
                while (child_tail->next) {
                    child_tail = child_tail->next;
                }

                // เชื่อม curr เข้ากับหัวของกิ่งลูก
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;

                // เชื่อมท้ายของกิ่งลูกเข้ากับ next เดิม
                child_tail->next = next;
                if (next) {
                    next->prev = child_tail;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};