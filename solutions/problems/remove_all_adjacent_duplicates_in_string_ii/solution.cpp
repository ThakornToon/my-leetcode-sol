class Solution {
public:
    string removeDuplicates(string s, int k) {
        // ใช้ vector แทน stack
        vector<pair<char, int>> st;
        
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                // เพิ่ม count
                st.back().second++;
                
                // ตรวจสอบถ้าถึง k
                if (st.back().second == k) {
                    st.pop_back();
                }
            } else {
                st.push_back({c, 1});
            }
        }
        
        // สร้างผลลัพธ์
        string result;
        for (auto& [c, count] : st) {
            result.append(count, c);
        }
        
        return result;
    }
};