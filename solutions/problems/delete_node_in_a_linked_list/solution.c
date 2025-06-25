/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    // คัดลอกค่าจากโหนดถัดไปมาใส่โหนดปัจจุบัน
    node->val = node->next->val;
    // ข้ามโหนดถัดไป (ลบโหนดถัดไป)
    node->next = node->next->next;
}