class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        
        // แยกตัวอักษรตาม parity
        vector<char> even_s1, odd_s1, even_s2, odd_s2;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even_s1.push_back(s1[i]);
                even_s2.push_back(s2[i]);
            } else {
                odd_s1.push_back(s1[i]);
                odd_s2.push_back(s2[i]);
            }
        }
        
        // เรียงลำดับและเปรียบเทียบ
        sort(even_s1.begin(), even_s1.end());
        sort(even_s2.begin(), even_s2.end());
        sort(odd_s1.begin(), odd_s1.end());
        sort(odd_s2.begin(), odd_s2.end());
        
        return even_s1 == even_s2 && odd_s1 == odd_s2;
    }
};