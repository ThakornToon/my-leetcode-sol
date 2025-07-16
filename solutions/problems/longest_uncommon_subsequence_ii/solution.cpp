class Solution {
private:
    bool isSubsequence(const string& a, const string& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.size();
    }
public:
    int findLUSlength(vector<string>& strs) {
        // เรียงตามความยาวสตริง มากไปน้อย
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        
        for (int i = 0; i < strs.size(); ++i) {
            bool isUncommon = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            if (isUncommon) {
                return strs[i].size();
            }
        }
        
        return -1;
    }
};