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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        
        int chunk_size = n / k;
        int extra = n % k;
        
        vector<ListNode*> res(k, nullptr);
        curr = head;
        
        for (int i = 0; i < k && curr != nullptr; i++) {
            res[i] = curr;
            int current_part_size = chunk_size + (i < extra ? 1 : 0);
            
            for (int j = 1; j < current_part_size; j++) {
                curr = curr->next;
            }
            
            ListNode* next_node = curr->next;
            curr->next = nullptr; // ตัดขาดลิงก์เพื่อแยกส่วน
            curr = next_node;
        }
        return res;
    }
};