/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    // Find middle
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next; 
        fast = fast->next->next;
    }
    
    // Reverse second half
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;
    
    // Compare halves
    bool result = true;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    return result;    
}