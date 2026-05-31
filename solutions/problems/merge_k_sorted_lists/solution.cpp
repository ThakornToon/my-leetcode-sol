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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        
        // 1. รวบรวมค่าทั้งหมดจากทุก linked list
        for (ListNode* head : lists) {
            ListNode* current = head;
            while (current != nullptr) {
                values.push_back(current->val);
                current = current->next;
            }
        }
        
        // 2. ถ้าไม่มีข้อมูลเลย คืนค่า nullptr
        if (values.empty()) {
            return nullptr;
        }
        
        // 3. เรียงลำดับค่าทั้งหมด
        sort(values.begin(), values.end());
        
        // 4. สร้าง linked list ใหม่จากค่าที่เรียงแล้ว
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        
        for (int i = 1; i < values.size(); i++) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        
        return head;
    }
};