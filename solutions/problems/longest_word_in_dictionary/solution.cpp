class Solution {
public:
    string longestWord(vector<string>& words) {
        // เรียงลำดับ: ความยาวน้อยไปมาก, ถ้าเท่ากันเรียงตามตัวอักษร
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.length() != b.length()) return a.length() < b.length();
            return a < b;
        });

        unordered_set<string> built;
        built.insert(""); // สตริงว่างถือว่าสร้างได้เสมอ
        string result = "";

        for (const string& word : words) {
            // ตรวจสอบว่า prefix (ตัดตัวสุดท้ายออก) เคยถูกสร้างหรือยัง
            if (built.count(word.substr(0, word.length() - 1))) {
                built.insert(word);
                if (word.length() > result.length()) {
                    result = word;
                }
            }
        }
        return result;
    }
};