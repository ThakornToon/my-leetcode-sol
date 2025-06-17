class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        
        stack<pair<int, int>> st;
        unordered_set<string> visited;
        st.push({0, 0});
        
        while (!st.empty()) {
            auto [a, b] = st.top(); // ดึงสถานะจากเหยือก x, y อันแรก
            st.pop();
            
            if (a + b == target) return true;
            
            string state = to_string(a) + "," + to_string(b);
            if (visited.count(state)) continue; // เก็บสถานะที่เคยผ่านมาแล้ว
            visited.insert(state);
            
            // เติมน้ำเต็มเหยือก
            st.push({x, b});
            st.push({a, y});
            
            // เทน้ำทิ้ง
            st.push({0, b});
            st.push({a, 0});
            
            // เทน้ำระหว่างเหยือก
            int pour1 = min(a, y - b);
            st.push({a - pour1, b + pour1});
            
            int pour2 = min(b, x - a);
            st.push({a + pour2, b - pour2});
        }
        return false;
    }
};