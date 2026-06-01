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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        
        // ใช้ stack เก็บโหนด
        stack<ListNode*> st;
        
        // สร้าง dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            // Push k โหนดลง stack
            int count = 0;
            while (curr != nullptr && count < k) {
                st.push(curr);
                curr = curr->next;
                count++;
            }
            
            // ถ้ามีครบ k โหนด
            if (count == k) {
                // Pop ออกจาก stack เพื่อกลับลำดับ
                while (!st.empty()) {
                    tail->next = st.top();
                    st.pop();
                    tail = tail->next;
                }
                tail->next = nullptr;
            } else {
                // เหลือน้อยกว่า k โหนด ต้องรักษาลำดับเดิม
                // stack มีลำดับย้อนกลับ (เพราะ push ตามลำดับ)
                // ใช้ vector ช่วยเก็บเพื่อกลับลำดับอีกครั้ง
                vector<ListNode*> temp;
                while (!st.empty()) {
                    temp.push_back(st.top());
                    st.pop();
                }
                // temp มีลำดับย้อนกลับ (จากท้ายไปหน้า)
                // ต้องต่อท้ายจากต้นไปท้าย
                for (int i = temp.size() - 1; i >= 0; i--) {
                    tail->next = temp[i];
                    tail = tail->next;
                }
                tail->next = nullptr;
            }
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};