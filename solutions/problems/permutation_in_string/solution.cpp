class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) return false;

        unordered_map<char, int> freq1, freq2;
        
        // Initialize frequency maps
        for (char c : s1) freq1[c]++;
        for (int i = 0; i < len1; i++) freq2[s2[i]]++;
        
        // Check initial window
        if (freq1 == freq2) return true;
        
        // Slide the window
        for (int i = len1; i < len2; i++) {
            // Remove the leftmost character
            char left = s2[i - len1];
            if (--freq2[left] == 0) freq2.erase(left);
            
            // Add new character
            freq2[s2[i]]++;
            
            // Compare maps
            if (freq1 == freq2) return true;
        }
        
        return false;
    }
};