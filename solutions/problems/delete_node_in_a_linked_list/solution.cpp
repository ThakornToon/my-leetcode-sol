/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // คัดลอกค่าจากโหนดถัดไปมาใส่โหนดปัจจุบัน
        node->val = node->next->val;
        // ข้ามโหนดถัดไป (ลบโหนดถัดไป)
        node->next = node->next->next;
    }
};