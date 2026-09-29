/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();

        // กรณีเป็นตัวเลขเดี่ยวๆ ไม่มีวงเล็บก้ามปู
        if (s[0] != '[') {
            return NestedInteger(std::stoi(s));
        }

        stack<NestedInteger> st;
        int num = 0;
        int sign = 1;
        bool has_num = false;

        for (char c : s) {
            if (c == '[') {
                st.push(NestedInteger()); // สร้าง NestedInteger ชนิด list ว่าง
            } else if (c == '-') {
                sign = -1;
            } else if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                has_num = true;
            } else if (c == ',' || c == ']') {
                if (has_num) {
                    st.top().add(NestedInteger(sign * num));
                    num = 0;
                    sign = 1;
                    has_num = false;
                }

                // เมื่อปิด list ชั้นย่อย ให้นำไปต่อเข้ากับ list แม่
                if (c == ']' && st.size() > 1) {
                    NestedInteger completed = st.top();
                    st.pop();
                    st.top().add(completed);
                }
            }
        }

        return st.top();
    }
};