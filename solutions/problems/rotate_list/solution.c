/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int l = 0;
    struct ListNode* curr = head;
    struct ListNode* last = NULL;
    while(curr != NULL) {
        last = curr;
        curr = curr->next; 
        l++;
    }
    if (l == 0) return head;
    k = k % l;
    if (k == 0) return head;
    curr = head;
    for(int i=0; i < l-k-1; i++){ 
        curr = curr->next; 
    }
    last->next = head; 
    head = curr->next;
    curr->next = NULL;
    return head;
}