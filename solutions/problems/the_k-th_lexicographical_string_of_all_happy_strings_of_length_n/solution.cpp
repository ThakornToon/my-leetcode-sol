class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * pow(2, n - 1);
        if (k > total) return "";
        
        string result;
        int remaining = k;
        int groupSize = total / 3;
        
        // หาตัวแรก
        int firstIndex = (remaining - 1) / groupSize;
        result.push_back('a' + firstIndex);
        remaining -= firstIndex * groupSize;
        
        // หาตัวที่เหลือ
        for (int i = 1; i < n; i++) {
            groupSize /= 2;
            char prev = result.back();
            
            // choices ที่เป็นไปได้
            vector<char> choices;
            for (char c = 'a'; c <= 'c'; c++) {
                if (c != prev) choices.push_back(c);
            }
            
            int choiceIndex = (remaining - 1) / groupSize;
            result.push_back(choices[choiceIndex]);
            remaining -= choiceIndex * groupSize;
        }
        
        return result;
    }
};