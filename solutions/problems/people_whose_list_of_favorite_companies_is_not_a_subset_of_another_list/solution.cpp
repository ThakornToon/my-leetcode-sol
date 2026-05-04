class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        
        // Sort แต่ละ list และเก็บเป็น vector
        vector<vector<string>> sortedCompanies(n);
        for (int i = 0; i < n; i++) {
            sortedCompanies[i] = favoriteCompanies[i];
            sort(sortedCompanies[i].begin(), sortedCompanies[i].end());
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            bool isSubset = false;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (sortedCompanies[i].size() > sortedCompanies[j].size()) continue;
                
                // two pointers ตรวจสอบว่า sortedCompanies[i] ⊆ sortedCompanies[j]
                int p1 = 0, p2 = 0;
                int len1 = sortedCompanies[i].size();
                int len2 = sortedCompanies[j].size();
                
                while (p1 < len1 && p2 < len2) {
                    if (sortedCompanies[i][p1] == sortedCompanies[j][p2]) {
                        p1++;
                        p2++;
                    } else if (sortedCompanies[i][p1] > sortedCompanies[j][p2]) {
                        p2++;
                    } else {
                        break; // sortedCompanies[i][p1] < sortedCompanies[j][p2] -> ไม่เจอ
                    }
                }
                
                if (p1 == len1) { // เจอครบทุกตัว
                    isSubset = true;
                    break;
                }
            }
            if (!isSubset) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};