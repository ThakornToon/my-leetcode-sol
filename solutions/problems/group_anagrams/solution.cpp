class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        for (string& s : strs) {
            // เรียงลำดับตัวอักษรในสตริง
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            
            // ใช้ sorted string เป็น key
            map[sorted].push_back(s);
        }
        
        // แปลง map เป็น vector ของ groups
        vector<vector<string>> result;
        for (auto& pair : map) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};