class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // รหัสมอร์สสำหรับ a-z
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.",
            "....","..",".---","-.-",".-..","--","-.",
            "---",".--.","--.-",".-.","...","-","..-",
            "...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> uniqueCodes;
        
        for (const string& word : words) {
            string morseCode = "";
            for (char c : word) {
                morseCode += morse[c - 'a'];  // แปลงตัวอักษรเป็นรหัสมอร์ส
            }
            uniqueCodes.insert(morseCode);
        }
        
        return uniqueCodes.size();
    }
};