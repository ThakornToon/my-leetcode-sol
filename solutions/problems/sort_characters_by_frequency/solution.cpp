class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;

        // นับความถี่
        for (char c : s) {
            freqMap[c]++;
        }

        // สร้าง vector ของคู่ char-frequency
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

        // เรียงลำดับตามความถี่
        sort(freqVec.begin(), freqVec.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        // สร้างสตริงผลลัพธ์
        string result;
        for (auto& p : freqVec) {
            result.append(string(p.second, p.first));
        }

        return result;
    }
};