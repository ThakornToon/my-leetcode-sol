class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int s2 = INT_MIN; 
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            // ถ้าเจอ nums[i] ที่น้อยกว่า s2 แสดงว่าพบ pattern
            if (nums[i] < s2) {
                return true;
            }
            
            // รักษา stack ให้เรียงจากมากไปน้อย
            while (!st.empty() && st.top() < nums[i]) { // จะมี s2 ก็ต่อเมื่อหา s3 ได้แล้ว
                s2 = st.top();  // อัพเดท s2 ให้เป็นค่าที่ใหญ่ที่สุดที่เป็นไปได้
                st.pop();
            }
            
            st.push(nums[i]);
        }
        return false;
    }
};