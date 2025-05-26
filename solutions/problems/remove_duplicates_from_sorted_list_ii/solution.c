/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* res = head;
    struct ListNode* temp = NULL;
    while (head && head->next) {
        if (head->val == head->next->val) {
            while (head->next && head->val == head->next->val) {
                struct ListNode* del = head->next;
                head->next = head->next->next;
                free(del);
            }

            if (head->next == NULL) {
                if(temp == NULL) {
                    return temp;
                }
                temp->next = NULL;
            }
            else {
                head->val = head->next->val;
                struct ListNode* del = head->next;
                head->next = head->next->next;
                free(del);
            }
        }
        else {
            temp = head;
            head = head->next;
        }
    }
    return res;
}