class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int numTeams = votes[0].size();
        
        // positionCount[team][position] = จำนวนโหวต
        vector<vector<int>> positionCount(26, vector<int>(numTeams, 0));
        
        // นับคะแนน
        for (const string& vote : votes) {
            for (int i = 0; i < numTeams; i++) {
                positionCount[vote[i] - 'A'][i]++;
            }
        }
        
        // สร้างรายชื่อทีม
        string teams = votes[0];
        
        // เรียงลำดับทีม
        sort(teams.begin(), teams.end(), [&](char a, char b) {
            // เปรียบเทียบทีละตำแหน่ง
            for (int i = 0; i < numTeams; i++) {
                if (positionCount[a - 'A'][i] != positionCount[b - 'A'][i]) {
                    return positionCount[a - 'A'][i] > positionCount[b - 'A'][i];
                }
            }
            // ถ้าเสมอทั้งหมด ให้เรียงตามตัวอักษร
            return a < b;
        });
        
        return teams;
    }
};