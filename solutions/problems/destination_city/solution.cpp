class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sources;
        
        // เก็บ source cities
        for (auto& path : paths) {
            sources.insert(path[0]);
        }
        
        // หา destination ที่ไม่ใช่ source
        for (auto& path : paths) {
            if (sources.find(path[1]) == sources.end()) {
                return path[1];
            }
        }
        
        return "";
    }
};