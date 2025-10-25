class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> bad;
        int n = fronts.size();
        
        // เก็บเลขที่ปรากฏทั้งสองด้านของบัตรเดียวกัน
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                bad.insert(fronts[i]);
            }
        }
        
        int answer = INT_MAX;
        
        // ดูทุกเลขใน fronts และ backs
        for (int i = 0; i < n; i++) {
            if (bad.find(fronts[i]) == bad.end()) {
                answer = min(answer, fronts[i]);
            }
            if (bad.find(backs[i]) == bad.end()) {
                answer = min(answer, backs[i]);
            }
        }
        
        return answer == INT_MAX ? 0 : answer;
    }
};