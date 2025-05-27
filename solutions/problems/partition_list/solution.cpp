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
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftlist = new ListNode(0, nullptr);
        ListNode* rightlist = new ListNode(0, nullptr);
        ListNode* small = leftlist;
        ListNode* big = rightlist;

        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }

        small->next = rightlist->next;
        big->next = nullptr;

        ListNode* result = leftlist->next;
        delete leftlist;
        delete rightlist;
        return result;
    }
};