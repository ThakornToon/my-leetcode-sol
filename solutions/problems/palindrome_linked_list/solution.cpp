/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* curr = head;
        
        // Push all elements onto stack
        while (curr) {
            s.push(curr->val);
            curr = curr->next;
        }
        
        // Compare with original list
        curr = head;
        while (curr) {
            if (curr->val != s.top()) {
                return false;
            }
            s.pop();
            curr = curr->next;
        }
        
        return true;
    }
};