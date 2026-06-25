class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        int len1 = word1.length(), len2 = word2.length();
        
        // จองพื้นที่ล่วงหน้าเพื่อประสิทธิภาพ
        result.reserve(len1 + len2);
        
        // สลับกันนำตัวอักษร
        while (i < len1 && j < len2) {
            result.push_back(word1[i++]);
            result.push_back(word2[j++]);
        }
        
        // ต่อตัวอักษรที่เหลือ
        if (i < len1) {
            result.append(word1.substr(i));
        }
        if (j < len2) {
            result.append(word2.substr(j));
        }
        
        return result;

    }
};