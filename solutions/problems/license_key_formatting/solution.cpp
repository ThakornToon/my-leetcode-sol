class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned;
        // ลบ '-' และแปลงเป็นตัวพิมพ์ใหญ่
        for (char c : s) {
            if (c != '-') {
                cleaned += toupper(c);
            }
        }
        
        if (cleaned.empty()) return "";
        
        int len = cleaned.size();
        int dashes = (len - 1) / k;
        string result;
        result.reserve(len + dashes);
        
        int first_group_size = len % k;
        if (first_group_size == 0) first_group_size = k;
        
        // กลุ่มแรก
        result.append(cleaned.substr(0, first_group_size));
        
        // กลุ่มที่เหลือ
        for (int i = first_group_size; i < len; i += k) {
            result += '-';
            result.append(cleaned.substr(i, k));
        }
        
        return result;
    }
};