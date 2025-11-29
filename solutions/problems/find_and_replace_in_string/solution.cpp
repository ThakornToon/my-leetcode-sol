class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<pair<int, int>> sorted_indices;
        
        // สร้าง index mapping และเรียงลำดับ
        for (int i = 0; i < n; i++) {
            sorted_indices.push_back({indices[i], i});
        }
        sort(sorted_indices.begin(), sorted_indices.end());
        
        string result;
        int last_pos = 0;
        
        for (auto& [pos, idx] : sorted_indices) {
            if (pos < last_pos) {
                continue;
            }
            string source = sources[idx];
            string target = targets[idx];
            
            // เพิ่มส่วนก่อน replacement
            result += s.substr(last_pos, pos - last_pos);
            
            // ตรวจสอบว่า source ตรงกับ substring ใน s หรือไม่
            if (s.substr(pos, source.length()) == source) {
                result += target;
                last_pos = pos + source.length();
            } else {
                // ถ้าไม่ตรง ให้ข้ามและรักษาตำแหน่งเดิม
                last_pos = pos;
            }
        }
        
        // เพิ่มส่วนที่เหลือ
        result += s.substr(last_pos);
        
        return result;
    }
};