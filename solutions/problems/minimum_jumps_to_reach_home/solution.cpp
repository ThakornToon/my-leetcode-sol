class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // a > b เรารู้ว่าถ้าเดินเกิน x+b จะกลับมาไม่ได้แน่นอน
        // a < b เป็นไปได้เยอะ ถ้า P > x ทุกการขยับไปหน้า 1 ครั้ง ต้องถอยหลัง b/a ครั้งเพื่อกลับมา

        // Pn > x -> P0 = x + b
        // Pn >= x + b ดังนั้น Pn - a >= x + b - a 
        // b - a > 0 ดังนั้น x + b - a > x แสดงว่า Pn - a >= P0 - a > x
        // Pn + b > Pn >= x + b ดังนั้น upper = max(x, max(forbidden)) + b 

        // P = x + b + k*a - m*b -> จำนวนรอบในการกลับ = (P - x) / (b - a)

        // max(x, max(forbidden)) + b อาจพาไปติด forbidden อีก
        // ต้องเผื่อ +a เพื่อกระโดดข้าม forbidden นั้น
        // เราไม่ต้องการไปเกิน x + a + b เพราะถ้าไปเกินแล้ว จะต้องใช้จังหวะถอยกลับ แต่ a < b ทำให้การถอยกลับไม่คุ้ม
    
    
        int upper = max(x, *max_element(forbidden.begin(), forbidden.end())) + b + a;
        
        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
        vector<vector<bool>> visited(upper + 1, vector<bool>(2, false));
        // visited[pos][0] = มาถึง pos โดยก้าวล่าสุดเป็น forward
        // visited[pos][1] = มาถึง pos โดยก้าวล่าสุดเป็น backward
        
        queue<tuple<int, int, int>> q; // (position, isBack, steps)
        q.push({0, 0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [pos, isBack, steps] = q.front();
            q.pop();
            
            if (pos == x) {
                return steps;
            }
            
            // ขยับไปข้างหน้า (a) - forward
            int forward = pos + a;
            if (forward <= upper && !forbiddenSet.count(forward) && !visited[forward][0]) {
                visited[forward][0] = true;
                q.push({forward, 0, steps + 1});
            }
            
            // ขยับถอยหลัง (b) - backward
            int backward = pos - b;
            if (backward >= 0 && !forbiddenSet.count(backward) && !visited[backward][1] && !isBack) {
                visited[backward][1] = true;
                q.push({backward, 1, steps + 1});
            }
        }
        
        return -1;
    }
};