class Solution {
public:
    string defangIPaddr(string address) {
        string result = address;
        size_t pos = 0;
        
        while ((pos = result.find('.', pos)) != std::string::npos) {
            result.replace(pos, 1, "[.]");
            pos += 3; // ข้าม "[.]" ที่เพิ่งเพิ่ม
        }
        
        return result;
    }
};