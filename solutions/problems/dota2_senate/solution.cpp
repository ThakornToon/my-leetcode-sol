class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;
        
        // เก็บ index ของสมาชิกแต่ละพรรค
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        
        // จำลองกระบวนการโหวต
        while (!radiant.empty() && !dire.empty()) {
            int r_index = radiant.front();
            int d_index = dire.front();
            radiant.pop();
            dire.pop();
            
            if (r_index < d_index) {
                // R โหวตก่อน และห้าม D
                radiant.push(r_index + n);
            } else {
                // D โหวตก่อน และห้าม R
                dire.push(d_index + n);
            }
        }
        
        return radiant.empty() ? "Dire" : "Radiant";
    }
};