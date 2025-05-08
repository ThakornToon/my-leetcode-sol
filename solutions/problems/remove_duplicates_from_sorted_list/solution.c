/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* res = head;
    while (head && head->next) {
        if (head->val == head->next->val) {
            head->next = head->next->next;
        } 
        else {
            head = head->next;
        }
    }
    return res;
}